#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

const int COD_EMPATE = 5;

const int COD_VITORIA = 11;

const int COD_DERROTA = 12;

const int CONTINUE_JOGANDO = 22;

char casas [3][3];

void mostrarMatriz (void);

void iniciarMatriz (void);

void receberJogadaDoUsuario (void);

void receberJogadaDaCPU (void);

int checarVencedor (void);

int tratamento(int retorno_checar_vencedor);



int main (){

	setlocale(LC_ALL, "Portuguese");	

	iniciarMatriz ();

	int retorno_checa_vencedor;
	
	while (1) {
			
		mostrarMatriz ();

		printf ("\n");

		printf ("Sua vez:\n");

		printf ("\n");

		receberJogadaDoUsuario();		

		if(tratamento(checarVencedor()) == 0) break;

		receberJogadaDaCPU();

		if(tratamento(checarVencedor()) == 0) break;
	
	} 
	
}



void iniciarMatriz (){

	int i, j;

	for (i = 0; i < 3; i++)
	
		for (j = 0; j < 3; j++) casas [i][j] = ' ';		
}



void mostrarMatriz (){

	system ("cls");

	int t; 	

	for (t = 0; t < 3; t++){
	
		printf ("\t %c | %c | %c ", casas [t][0], casas [t][1], casas [t][2]);	
		
		if (t != 2) printf ("\n\t---|---|---\n");
	}
	
	printf ("\n");
}





void receberJogadaDoUsuario (void){

	int l, c;

	setlocale(LC_ALL, "Portuguese");

	while (1){
		
		printf ("\n");

		printf ("Digite linha (posição de 1 a 3): ");

		scanf ("%i", &l);

		printf ("\n");

		printf ("Digite coluna (posição de 1 a 3):");

		scanf ("%i", &c);

		printf ("\n");

			if (l < 1 || c < 1 || l > 3 || c > 3){

				l = 0;
				c = 0;	

				printf ("\n");

				printf ("Jogada inválida, tente novamente.");

				printf ("\n");	
			}

			else if (casas [l-1][c-1] != ' '){

				l = 0;
				c = 0;	

				printf ("\n");

				printf ("Jogada inválida, tente novamente.");

				printf ("\n");			
			}

			else {

				casas [l-1][c-1] = 'O';	

				break;	
			}	
	}
			
}



void receberJogadaDaCPU (void){

	int i, j;

	if (casas [0][0] == 'X' && casas [0][1] == 'X' &&  casas [0][2] == ' ') casas [0][2] = 'X';	
				
	else if (casas [1][0] == 'X' && casas [1][1] == 'X' &&  casas [1][2] == ' ') casas [1][2] = 'X';	

	else if (casas [2][0] == 'X' && casas [2][1] == 'X' &&  casas [2][2] == ' ') casas [2][2] = 'X';
			
	else if (casas [0][0] == 'X' && casas [0][1] == ' ' &&  casas [0][2] == 'X') casas [0][1] = 'X';	
				
	else if (casas [1][0] == 'X' && casas [1][1] == ' ' &&  casas [1][2] == 'X') casas [1][1] = 'X';	

	else if (casas [2][0] == 'X' && casas [2][1] == ' ' &&  casas [2][2] == 'X') casas [2][1] = 'X';
			
	else if (casas [0][0] == ' ' && casas [0][1] == 'X' &&  casas [0][2] == 'X') casas [0][0] = 'X';	
				
	else if (casas [1][0] == ' ' && casas [1][1] == 'X' &&  casas [1][2] == 'X') casas [1][0] = 'X';	

	else if (casas [2][0] == ' ' && casas [2][1] == 'X' &&  casas [2][2] == 'X') casas [2][0] = 'X';
						
	else if (casas [0][0] == 'X' && casas [1][0] == 'X' &&  casas [2][0] == ' ') casas [2][0] = 'X';

	else if (casas [0][1] == 'X' && casas [1][1] == 'X' &&  casas [2][1] == ' ') casas [2][1] = 'X';	

	else if (casas [0][2] == 'X' && casas [1][2] == 'X' &&  casas [2][2] == ' ') casas [2][2] = 'X';
			
	else if (casas [0][0] == 'X' && casas [1][0] == ' ' &&  casas [2][0] == 'X') casas [1][0] = 'X';

	else if (casas [0][1] == 'X' && casas [1][1] == ' ' &&  casas [2][1] == 'X') casas [1][1] = 'X';	

	else if (casas [0][2] == 'X' && casas [1][2] == ' ' &&  casas [2][2] == 'X') casas [1][2] = 'X';
			
	else if (casas [0][0] == ' ' && casas [1][0] == 'X' &&  casas [2][0] == 'X') casas [0][0] = 'X';

	else if (casas [0][1] == ' ' && casas [1][1] == 'X' &&  casas [2][1] == 'X') casas [0][1] = 'X';	

	else if (casas [0][2] == ' ' && casas [1][2] == 'X' &&  casas [2][2] == 'X') casas [0][2] = 'X';
			
	else if (casas [0][0] == ' ' && casas [1][1] == 'X' &&  casas [2][2] == 'X') casas [0][0] = 'X';
			
	else if (casas [0][0] == 'X' && casas [1][1] == ' ' &&  casas [2][2] == 'X') casas [1][1] = 'X';

	else if (casas [0][0] == 'X' && casas [1][1] == 'X' &&  casas [2][2] == ' ') casas [2][2] = 'X';
			
	else if (casas [2][0] == ' ' && casas [1][1] == 'X' &&  casas [0][2] == 'X') casas [2][0] = 'X';
			
	else if (casas [2][0] == 'X' && casas [1][1] == ' ' &&  casas [2][2] == 'X') casas [1][1] = 'X';

	else if (casas [2][0] == 'X' && casas [1][1] == 'X' &&  casas [0][2] == ' ') casas [0][2] = 'X';
		
		
	else if (casas [0][0] == 'O' && casas [0][1] == 'O' &&  casas [0][2] == ' ') casas [0][2] = 'X';	
				
	else if (casas [1][0] == 'O' && casas [1][1] == 'O' &&  casas [1][2] == ' ') casas [1][2] = 'X';	

	else if (casas [2][0] == 'O' && casas [2][1] == 'O' &&  casas [2][2] == ' ') casas [2][2] = 'X';
			
	else if (casas [0][0] == 'O' && casas [0][1] == ' ' &&  casas [0][2] == 'O') casas [0][1] = 'X';	
				
	else if (casas [1][0] == 'O' && casas [1][1] == ' ' &&  casas [1][2] == 'O') casas [1][1] = 'X';	

	else if (casas [2][0] == 'O' && casas [2][1] == ' ' &&  casas [2][2] == 'O') casas [2][1] = 'X';
			
	else if (casas [0][0] == ' ' && casas [0][1] == 'O' &&  casas [0][2] == 'O') casas [0][0] = 'X';	
				
	else if (casas [1][0] == ' ' && casas [1][1] == 'O' &&  casas [1][2] == 'O') casas [1][0] = 'X';	

	else if (casas [2][0] == ' ' && casas [2][1] == 'O' &&  casas [2][2] == 'O') casas [2][0] = 'X';
						
	else if (casas [0][0] == 'O' && casas [1][0] == 'O' &&  casas [2][0] == ' ') casas [2][0] = 'X';

	else if (casas [0][1] == 'O' && casas [1][1] == 'O' &&  casas [2][1] == ' ') casas [2][1] = 'X';	

	else if (casas [0][2] == 'O' && casas [1][2] == 'O' &&  casas [2][2] == ' ') casas [2][2] = 'X';
			
	else if (casas [0][0] == 'O' && casas [1][0] == ' ' &&  casas [2][0] == 'O') casas [1][0] = 'X';

	else if (casas [0][1] == 'O' && casas [1][1] == ' ' &&  casas [2][1] == 'O') casas [1][1] = 'X';	

	else if (casas [0][2] == 'O' && casas [1][2] == ' ' &&  casas [2][2] == 'O') casas [1][2] = 'X';
			
	else if (casas [0][0] == ' ' && casas [1][0] == 'O' &&  casas [2][0] == 'O') casas [0][0] = 'X';

	else if (casas [0][1] == ' ' && casas [1][1] == 'O' &&  casas [2][1] == 'O') casas [0][1] = 'X';	

	else if (casas [0][2] == ' ' && casas [1][2] == 'O' &&  casas [2][2] == 'O') casas [0][2] = 'X';
			
	else if (casas [0][0] == ' ' && casas [1][1] == 'O' &&  casas [2][2] == 'O') casas [0][0] = 'X';
			
	else if (casas [0][0] == 'O' && casas [1][1] == ' ' &&  casas [2][2] == 'O') casas [1][1] = 'X';

	else if (casas [0][0] == 'O' && casas [1][1] == 'O' &&  casas [2][2] == ' ') casas [2][2] = 'X';
			
	else if (casas [2][0] == ' ' && casas [1][1] == 'O' &&  casas [0][2] == 'O') casas [2][0] = 'X';
			
	else if (casas [2][0] == 'O' && casas [1][1] == ' ' &&  casas [2][2] == 'O') casas [1][1] = 'X';

	else if (casas [2][0] == 'O' && casas [1][1] == 'O' &&  casas [0][2] == ' ') casas [0][2] = 'X';
			
	else {
				
		do {
					
			srand (time(NULL));

			i = rand()%3;

			j = rand()%3;

			casas [i][j] = 'X';	
					
		} while (casas [i][j] == ' ');	
	}			
	
}



int checarVencedor (void){
	
	int i, j;

	///verifica as linhas///
	if (casas [0][0] == 'X' && casas [0][1] == 'X' &&  casas [0][2] == 'X') return COD_DERROTA;
	
	else if (casas [1][0] == 'X' && casas [1][1] == 'X' &&  casas [1][2] == 'X') return COD_DERROTA;	
	
	else if (casas [2][0] == 'X' && casas [2][1] == 'X' &&  casas [2][2] == 'X') return COD_DERROTA;
	
	else if (casas [0][0] == 'O' && casas [0][1] == 'O' &&  casas [0][2] == 'O') return COD_VITORIA;
	
	else if (casas [1][0] == 'O' && casas [1][1] == 'O' &&  casas [1][2] == 'O') return COD_VITORIA;	
	
	else if (casas [2][0] == 'O' && casas [2][1] == 'O' &&  casas [2][2] == 'O') return COD_VITORIA;

	///verifica as colunas///	 
	else if (casas [0][0] == 'X' && casas [1][0] == 'X' &&  casas [2][0] == 'X') return COD_DERROTA;
	
	else if (casas [0][1] == 'X' && casas [1][1] == 'X' &&  casas [2][1] == 'X') return COD_DERROTA;	
	
	else if (casas [0][2] == 'X' && casas [1][2] == 'X' &&  casas [2][2] == 'X') return COD_DERROTA;
	
	else if (casas [0][0] == 'O' && casas [1][0] == 'O' &&  casas [2][0] == 'O') return COD_VITORIA;
	
	else if (casas [0][1] == 'O' && casas [1][1] == 'O' &&  casas [2][1] == 'O') return COD_VITORIA;	
	
	else if (casas [0][2] == 'O' && casas [1][2] == 'O' &&  casas [2][2] == 'O') return COD_VITORIA;	
	
	///verifica as diagonais///
	else if (casas [0][0] == 'X' && casas [1][1] == 'X' &&  casas [2][2] == 'X') return COD_DERROTA;
	
	else if (casas [2][0] == 'X' && casas [1][1] == 'X' &&  casas [0][2] == 'X') return COD_DERROTA;
	
	else if (casas [0][0] == 'O' && casas [1][1] == 'O' &&  casas [2][2] == 'O') return COD_VITORIA;	
	
	else if (casas [2][0] == 'O' && casas [1][1] == 'O' &&  casas [0][2] == 'O') return COD_VITORIA;
		
	///verificar empate///
	int encontrou_vazio = 0;

	for (i = 0; i < 3; i++){
	
		for (j = 0; j < 3; j++) {
		
			if(casas [i][j] == ' '){
			
				encontrou_vazio = 1;
				break;
			}
		}
		
		if(encontrou_vazio)
			break;
	}

	if(!encontrou_vazio)
		return COD_EMPATE;	
			
	return CONTINUE_JOGANDO; 								
}



int tratamento(int retorno_checa_vencedor){

	if (retorno_checa_vencedor == COD_VITORIA){
	
		mostrarMatriz ();

		printf ("\n");

		printf ("Você ganhou!!!\n");

		printf ("\n");

		return 0;	
	} 
	
	else if (retorno_checa_vencedor == COD_DERROTA){
	
		mostrarMatriz ();

		printf ("\n");

		printf ("A CPU ganhou!!!\n");

		printf ("\n");	

		return 0;	
	} 	
	
	else if (retorno_checa_vencedor == COD_EMPATE){
	
		mostrarMatriz ();

		printf ("\n");

		printf ("Jogo empatado!!!\n");

		printf ("\n");

		return 0;	
	} 
	
	return 1;
}

