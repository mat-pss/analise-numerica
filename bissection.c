/* Método da Bissecção para o cálculo de raiz quadrada */

#include <stdio.h>
#include <math.h>


main()
{
double x, a, b, epsilon, ordem, razao, taxa, fb, fc;    /* x é o radicando e i o índice */
double c[4];	/* vetor c usado para estimar a ordem de convergencia */
int i, n, cont, sgn, sgn_b, sgn_c;

cont=0;
n=1000;
fc=1;

/* Entrada dos dados */

printf("Entre com o radicando: ");
scanf("%lf", &x);
printf("\n");
printf("Entre com o indice (inteiro >= 2): ");
scanf("%d", &i);
printf("\n");
printf("Entre com a precisao desejada: ");
scanf("%lf", &epsilon);
printf("\n");
printf("Entre com o intervalo [a,b] na forma 'a b': ");
scanf("%lf %lf", &a, &b);
printf("\n");

/*   Execução do método   */

while (cont<=n && fabs(fc)>=epsilon)
	{
	c[3]=0.5*(a+b); 
	printf("x%i = %lf\n", cont, c[3]);	
	if (cont>=3)
	   {
	   /* estimativa da ordem de convergencia: */
	   /* ordem = (log|e2|-log|e1|)/(log|e1|-log|e0|)  */
	   ordem=(log(fabs(c[3]-c[2]))-log(fabs(c[2]-c[1])))/(log(fabs(c[2]-c[1]))-log(fabs(c[1]-c[0])));
	   razao=fabs(c[3]/c[2]);
	   taxa=-log10(razao);
	   c[0]=c[1];
	   c[1]=c[2];
	   c[2]=c[3];
	   }
	else 
	    {
	    if (cont==0)
		   c[0]=c[3];
	    else if (cont==1)
				c[1]=c[3];
			 else if (cont==2)
				 	 c[2]=c[3];
	    }
	fb=pow(b,i)-x;
	fc=pow(c[3],i)-x;
	if (fb<0)
	   sgn_b=-1;
	else sgn_b=1;
	if (fc<0)
	   sgn_c=-1;
	else sgn_c=1;
	/* estratégia para evitar erros decorrentes de precisão (Burden & Faires) */
	sgn=sgn_b*sgn_c;  
	if (sgn<0)	
	   a=c[3];
	else b=c[3];
	++cont;
}

/* Apresentacao dos resultados: */

if (cont<=n)
	{
	printf("\n");
	printf("Raiz = %lf\n", c[3]);
	printf("O metodo convergiu apos %d iteracoes.\n", cont-1);
	if (razao<epsilon)
		printf("A convergencia e superlinear. Sua razao e: %lf. A taxa assintotica e: %lf\n", razao, taxa);
	else if (razao<1)
			printf("A convergencia e linear. Sua razao e: %lf. A taxa assintotica e: %lf\n", razao, taxa);
		else printf("A convergencia e sublinear. Sua razao e: %lf. A taxa assintotica e: %lf\n", razao, taxa, razao);
	printf("A ordem de convergencia estimada e de: %lf\n", ordem);
	}
else printf("O metodo nao convergiu apos 1000 iteracoes.\n");

}

