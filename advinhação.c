#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dificuldade(){

  //DEFINE A DIFICULDADE DO JOGO

   int tentativas, nivel;
    do{
        printf("Qual o nivel de dificuldade?\n");
        printf("Escolha: ");
        scanf("%d", &nivel);

        switch(nivel) {
            case 1:
                tentativas = 12;
                break;
            case 2:
                tentativas = 9;
                break;
            case 3:
                tentativas = 6;
                break;
            default:
                printf("ESCOLHA NAO PERMITIDA TENTE NOVAMENTE \n");
                continue;
        }

    }while(nivel != 1 && nivel != 2 && nivel != 3);


    if(nivel == 1){
        printf(":-)\n");
        printf("VOCE ESCOLHEU O NIVEL FACIL\n");

    }else if(nivel == 2){
        printf("   _____    \n");
        printf("  /     \\  \n");
        printf(" | O   O |  \n");
        printf(" |   ^   |  \n");
        printf(" |  '-'  |  \n");
        printf("  \\_____/  \n");
        printf("VOCE ESCOLHEU O NIVEL MEDIO\n");
    }else{
        printf("    _______     \n");
        printf("   /       \\   \n");
        printf("  /  O   O  \\  \n");
        printf(" /     ^     \\ \n");
        printf("|   \\_____/   |\n");
        printf(" \\___________/  \n");
        printf("    \\_____/     \n");
        printf("   /       \\    \n");
        printf("  |  _____  |    \n");
        printf("  | |     | |    \n");
        printf("   \\|_____|/    \n");
        printf("VOCE ESCOLHEU O NIVEL DIFICIL\n");
    }
return tentativas;
}

int funcTentativas(int tentativas, int *nTentativas,int *pontos){

    int chute, Pontos;

    if (tentativas == 12) {  // Fácil
        Pontos = 1200;
    } else if (dificuldade == 9) {  // Médio
        Pontos = 900;
    } else {  // Difícil
        Pontos = 600;
    }

    *pontos = Pontos;

    //GERA UM NUMERO ALEATORIO
    srand(time(0));
    int aleatorio = rand();
    //CONVERTE O NUMERO ALEATORIO DE 0 A 99
    float numerosecreto = aleatorio % 100;

    for(int i = 1 ; i <= tentativas ; i++){

        printf("Tenativa %d\n", i);
        printf("Qual eh o seu chute? ");
        scanf("%d", &chute);
        printf("seu chute foi %d\n", chute);

        //VERIFICA SE O NUMERO ESCOLHIDO É MENOR QUE ZERO
        if(chute < 0) {
            printf("Você nao pode chutar numeros negativos!\n");
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou){
                printf("parabens voce acertou ! \n");
                *nTentativas = i;
                return 1;
        }else if (maior){
            printf(" o numero escolhido eh maior do que o numero secreto\n");
        }else{
            printf("o numero escolhido eh menor do que o numero secreto\n");
        }

        //ATUALIZA PONTOS
        *pontos = Pontos - ((Pontos / tentativas) * i);
        *nTentativas = i;
    }

return -1;
}
