#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "advinhação.h"

int main()
{
    short int jogar = 0;

    do{
        //VARIAVEIS
        int tentativas, valor, pontos, nTentativas;

        printf("+-----------------------------+\n");
        printf("|   Adivinhe o Numero!        |\n");
        printf("+-----------------------------+\n");
        printf("|                             |\n");
        printf("|         ________            |\n");
        printf("|        |  ? ? ? |           |\n");
        printf("|         --------            |\n");
        printf("|                             |\n");
        printf("|  Niveis de Dificuldade:     |\n");
        printf("|  1. Facil   (10 tentativas) |\n");
        printf("|  2. Medio   (9 tentativas)  |\n");
        printf("|  3. Dificil (6 tentativas)  |\n");
        printf("|                             |\n");
        printf("|  Boa sorte!                 |\n");
        printf("|                             |\n");
        printf("+-----------------------------+\n");
        printf("         |   |    |            \n");
        printf("         |   |    |            \n");
        printf("        (1) (2)  (3)           \n");

        tentativas = dificuldade();

        valor = funcTentativas(tentativas,&nTentativas,&pontos);

        if(valor == 1){
            printf("FIM DE JOGO\n");
            printf("VOCE ACERTOU EM %d TENTATIVA!\n", nTentativas);
            printf("TOTAL DE PONTOS: %d\n", pontos);
        }else{
            printf("VOCE PERDEU\n");
            printf("VOCE ERROU AS %d TENTATIVAS!\n", nTentativas);
            printf("TOTAL DE PONTOS: %d\n", pontos);
        }

        do{
            printf("DESEJA JOGAR NOVAMENTE?\n");
            printf("SIM: 1 NAO: 2\n");
            scanf("%hd", &jogar);

            // VERIFICA SE A AENTRADA E VALIDA
            if (jogar != 1 && jogar != 2) {
                printf("ENTRADA INVALIDA! Por favor, escolha 1 para SIM ou 2 para NAO.\n");
            }
        } while (jogar != 1 && jogar != 2);

    }while(jogar == 1 );

return 0;
}
