// Informações do estudante
// Nome: Reynold Navarro Mazo
// Curso: Ci�ncia da Computa��o
// RA: 756188

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromoR(int i, int f, char *s)
{	
	
	if(s[0]==s[1]){
		return 1;
	}
	
	if(s[i]==s[f]){                           //faz a compara��o entre a primeira possi��o e a ultima da string
		
		if(i==f||s[i]==s[f+1]){               //verifica se a possi��o inicial � igual a final se isso ocorrer significa que todas as verifica��es iniciais foram verdadeiras
			return 1;						  //na segunda compara��o � para n�meros pares 
		}
		return palindromoR(i+1, f-1, s);      //chama a fun��o para a pr�xima compara��o
	}
	else
		return 0;
	
}



void palindromo(char *s)
{
    int saida = palindromoR(0, strlen(s) - 1, s);

    printf("\"");
    printf("%s", s);
    printf("\" ");

    if (saida)
    {
        printf("eh palindromo\n");
    }
    else
    {
        printf("nao eh palindromo\n");
    }
}

void inversaR(char *str)
{	
	if(*str=='\0'){                 //caso base que verifica se o ponteiro est� apontando para o fim(espa�o) de uma string  
	
	}	
	else{
		inversaR(str+1);           //anda o ponteiro para o �ltimo elemento 
		printf("%c", *str);        //printa o conte�do do ponteiro que est� no final d� palavra
					
	}
	
}

void inversa(char *s)
{
    printf("inversa de \"");
    printf("%s", s);
    printf("\" = ");
	
    inversaR(s);

    printf("\n");
}

int fibonacciR(int n)
{
	if (n==0){                   //caso base para sequ�ncia ser igual 0, retorna vazio
		return 0;
	}
	if (n==1){					//verifica que a sequ�ncia � igual a 1, para passar o valor 0 = sequ�ncia para 1 n�mero
		return 1;
	}
    else											
    	return fibonacciR(n-1) + fibonacciR(n-2);  //chama recursivamente a soma do pen�ltimo com o antipen�ltimo
}

void fibonacci(int n)
{
    int i;

    printf("%d primeiros numeros de fibonacci = ", n);
    for (i = 0; i < n; i++)
        printf("%d ", fibonacciR(i));

    printf("\n");
}

int pisoLogR(int x)
{
	if(x>1){                              // verifica se x>1, pois log de 0 n�o existe e x = 1 seria o resto da divis�o de um n�mero n�o divis�vel por 2
		return 1 + pisoLogR(x/2);         // faz a divis�o recursiva e soma 1 para obter o valor absoluto do log de 2 dos valores de x 
	}
	else
		return 0;
}

void pisoLog(int x)
{
    int valor = 0;
    printf("piso de log base 2 de %d = ", x);
    valor = pisoLogR(x);
    printf("%d\n", valor);
}

int main(int argc, char *argv[])
{
    int t;

    scanf("%d", &t);

    if (t < 1 || t > 4)
    {
        printf("Parametros incorretos.\n");
        printf("Ex:\n");
        printf("tp01_recursao 1 [para testar palindromo]\n");
        printf("tp01_recursao 2 [para testar inversa]\n");
        printf("tp01_recursao 3 [para testar fibonacci]\n");
        printf("tp01_recursao 4 [para testar pisoLog]\n");
    }

    if (t == 1)
    {
        printf("\nTestando palindromo()\n\n");
        palindromo("");
        palindromo("1");
        palindromo("77");
        palindromo("505");
        palindromo("1111");
        palindromo("2112");
        palindromo("369963");
        palindromo("10101");
        palindromo("1001001");
        palindromo("12");
        palindromo("12451");
        palindromo("100011");
    }
    else if (t == 2)
    {
        printf("\nTestando inversa()\n\n");
        inversaR("");
        inversa("ab");
        inversa("gato");
        inversa("minerva");
    }
    else if (t == 3)
    {
        printf("\nTestando fibonacci()\n\n");
        fibonacci(0);
        fibonacci(1);
        fibonacci(2);
        fibonacci(4);
        fibonacci(10);
    }
    else if (t == 4)
    {
        printf("\nTestando pisoLog()\n\n");
        pisoLog(1);
        pisoLog(2);
        pisoLog(3);
        pisoLog(4);
        pisoLog(5);
        pisoLog(15);
        pisoLog(16);
        pisoLog(17);
        pisoLog(127);
        pisoLog(256);
        pisoLog(511);
        pisoLog(512);
    }

    return 0;
}
