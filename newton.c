/* Método de Newton para o cálculo da raiz de uma funcao */

#include <stdio.h>
#include <math.h>


double funcao_1(double y)
{
double y0;
y0=exp(y)-y-2;
return(y0);
}

double funcao_2(double y)
{
double y0;
y0=-y+(2*y*y*y+5)/(3*y*y);
return(y0);
}


int main()
{
double x0, epsilon, ordem, razao, taxa, f, df;
double x[4];	/* vetor c usado para estimar a ordem de convergencia */
int funcao, n, cont;


/* Entrada dos dados */

printf("Funcao 1: f(x) = exp(x)-x-2     Funcao 2: f(x) = -x+(2x^3+5)/(3x^2) \n");
printf("Entre com a funcao: ");
scanf("%d", &funcao);
printf("\n");
printf("Entre com a precisao desejada: ");
scanf("%lf", &epsilon);
printf("\n");
printf("Entre com a estimativa inicial: ");
scanf("%lf", &x0);
printf("\n");

/*   Execução do método   */

cont=1;
n=10000;
f=1000;
x[2]=x0;
x[1]=0;

while (cont<=n && fabs(f)>=epsilon)
	{
     if (funcao==1) {
        f=funcao_1(x[2]);
        df=1e8*(funcao_1(x[2]+1e-8)-funcao_1(x[2]));
        }
    else {
        f=funcao_2(x[2]);
        df=1e8*(funcao_2(x[2]+1e-8)-funcao_2(x[2]));
        }
	x[3]=x[2]-f/df; 
	printf("x%d = %lf\n", cont, x[3]);	
	if (cont>=3)
	   {
	   /* estimativa da ordem de convergencia: */
	   /* ordem = (log|e2|-log|e1|)/(log|e1|-log|e0|)  */
	   ordem=(log(fabs(x[3]-x[2]))-log(fabs(x[2]-x[1])))/(log(fabs(x[2]-x[1]))-log(fabs(x[1]-x[0])));
	   razao=fabs(x[3]/x[2]);
       taxa=-log10(razao);
	   }
	x[0]=x[1];
	x[1]=x[2];
	x[2]=x[3];
    ++cont;
}

/* Apresentacao dos resultados: */

if (cont<=n)
	{
	printf("\n");
	printf("Raiz = %lf\n", x[3]);
	printf("O metodo convergiu apos %d iteracoes.\n", cont-1);
	if (razao<epsilon)
		printf("A convergencia e superlinear. Sua razao e: %lf A taxa assintotica e: %lf\n", razao, taxa);
	else if (razao<1)
			printf("A convergencia e linear. Sua razao e: %lf. A taxa assintotica e: %lf\n", razao, taxa);
		else printf("A convergencia e sublinear. Sua razao e: %lf A taxa assintotica e: %lf\n", razao, taxa);
	printf("A ordem de convergencia estimada e de: %lf\n", ordem);
	}
else printf("O metodo nao convergiu apos 10.000 iteracoes.\n");

}


