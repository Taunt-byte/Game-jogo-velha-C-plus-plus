#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void tabuleiro(char tabuleiro[3][3])
{
    system("cls");
    printf("\t %c | %c | %c  \n",tabuleiro[0][0],tabuleiro[0][1],tabuleiro[0][2]);
    printf("\t ---------\n");
    printf("\t %c | %c | %c  \n",tabuleiro[1][0],tabuleiro[1][1],tabuleiro[1][2]);
    printf("\t ---------\n");
    printf("\t %c | %c | %c  \n\n",tabuleiro[2][0],tabuleiro[2][1],tabuleiro[2][2]);
}

int main()
{
    char casas[3][3] = {
    	
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
		
	};

    char res, vencedor;
    int cont_jogadas, linha, coluna, vez = 0, i, j;
    do
    {
        cont_jogadas = 1;
        vencedor = 'N';
        
        for(i = 0; i<3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                casas[i][j]=' ';
            }
        }
        do
        {
            tabuleiro(casas);
            
            if(vez %2 == 0)
            {
            	
                printf("Jogador X\n");
                
            }
            else
            {
            	
                printf("Jogador O\n");
                
            }
            
            printf("Digite a linha: ");
            scanf("%i", &linha);
            
            printf("Digite a coluna: ");
            scanf("%i", &coluna);
            
            if(linha < 1 || coluna < 1 || linha > 3 || coluna > 3 )
            {
                linha = 0;
                coluna = 0;
            }
            else if(casas[linha - 1][coluna - 1] != ' ')
            {
                linha = 0;
                coluna = 0;
            }
			else
            {
                if(vez %2 == 0 )
                {
                    casas[linha - 1][coluna - 1] = 'X';
                    
                    if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X')
                    {
                    	
                    	vencedor = 'X';
					}
					
					if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X')
                    {
                    	
                    	vencedor = 'X';
					}
					
					if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X')
                    {
                    	
                    	vencedor = 'X';
					}
					
					if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X')
                    {
                    	
                    	vencedor = 'X';
					}
					
					if(casas[2][0] == 'X' && casas[1][1] == 'X' && casas[0][2] == 'X')
                    {
                    	
                    	vencedor = 'X';
					}
					
                }
                else
                {
                    casas[linha - 1][coluna - 1] = 'O';
                    
                    if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O')
                    {
                    	
                    	vencedor = 'O';
					}
					
					if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O')
                    {
                    	
                    	vencedor = 'O';
					}
					
						if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O')
                    {
                    	
                    	vencedor = 'O';
					}
					
					if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O')
                    {
                    	
                    	vencedor = 'O';
					}
					
					if(casas[2][0] == 'O' && casas[1][1] == 'O' && casas[0][2] == 'O')
                    {
                    	
                    	vencedor = 'O';
					}
					
                }
                
                vez++;
                cont_jogadas++;
                
            }
           
        }
        

        while(cont_jogadas != 10 && vencedor == 'N');
        tabuleiro(casas);
        	
        if(cont_jogadas == 10){
        		
        	printf("Deu velha!\n");
        	sleep(2);
        	system("cls");
        	
		}else{ 

			printf("O jogador %c ganhou!", vencedor);
			sleep(2);
			system("cls");
			
		}
		
        printf("Deseja jogar novamente?(Digite s para sim e n para nao): ");
        scanf("%s",&res);

        }
        
		while(res == 's');

     }