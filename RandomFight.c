#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct gameComponents {
    int totalRound, numMatch, cureCount;
    int matchWin, matchDraw, matchLost;
    int player, enemy;
    int vit, der, emp;
    int resVit, resDer;
    int roundWin, roundLose, roundDraw;
    int medicine
}Game;


int diceRoll(){
    int dados;
    srand(time(0));
    dados = (rand()%(5-0+1))+0;
    printf("\nDADO 0/5 = %d \n",dados);
    return dados;
}

int dmgRoll(){
    int dano;
    srand(time(0));
    dano = (rand()%(50-25+1))+25;
    return dano;
}

void gameSet() {
    Game.totalRound = 0;
    Game.player = 100;
    Game.enemy = 100;
    Game.medicine = 50;
    Game.cureCount = 0;
    Game.vit = 0;
    Game.der = 0;
    Game.emp = 0;
    Game.matchWin = 0;
    Game.matchDraw = 0;
    Game.matchLost = 0;
    Game.numMatch = 0;
    Game.roundWin = 0;
    Game.roundLose = 0;
    Game.roundDraw = 0;
}

void gameReset() {
    Game.totalRound = 0;
    Game.player = 100;
    Game.enemy = 100;
    Game.vit = 0;
    Game.der = 0;
    Game.emp = 0;
    Game.resVit = 0;
    Game.resDer = 0;
}

void instruction(){
    int press;
    printf("\n============== [REGRAS DO JOGO} ================\n");
        printf("\n1 - O Jogo consiste no sorteio de 1 numero aleatorio entre 0 e 5");
        printf("\n se o numero sorteado for menor ou igual a 2, o turno sera do inimigo");
        printf("\n se o numero for maior ou igual a 3, sera seu turno");
        printf("\n\t-TURNO DO JOGADOR-\n");
        printf("\n 1-[ATAQUE] \n 2-[SAIR]");
        printf("\n\n2 - Sistema de decisao de Vitoria/Empate/Derrota simples");
        printf("\nO Jogo conta com 2 Rounds, decidindo a partir deles os criterios");
        printf("\n * 2 Rounds ganhos = {Vitoria}");
        printf("\n * 2 Rounds perdidos = {Derrota}");
        printf("\n * 1 Round Ganho e 1 Round perdido = {Empate}");
        printf("\n");
        printf("\n=================[FIM]==========================\n");
        printf("\nAperte 1 para continuar\n");
        scanf("%d",&press);
        if (press==1){
            system("clear");
        }
}

int main(void){
    int op, esc, cont;
    int dado = 0, dano = 0;

    //Setting das Variáveis gerais//
    gameSet();

    do{
        printf("\n==========[Combate em C]==========\n ");
        printf("\n1-[JOGAR]\n");
        printf("\n2-[SAIR]\n");
        scanf("\n%d",&op);
            switch(op){
                case 1:
                printf("\n");
                instruction();
                break;
                
                case 2:
                printf("\nFIM DE JOGO\n");
                abort();
                break;
            }
    do{
        printf("\n========\nINICIO DE JOGO\n========\n");
        printf("Rolagem dos Dados\n");
        do{
            dado = diceRoll();
            dano = dmgRoll();
            if(dado<=2){
                printf("\n{ Partida %d }\nRound %d\n",Game.numMatch+1,Game.totalRound+1);
                printf("\nTURNO INIMIGO");
                printf("\n[ATAQUE]\n");
                Game.player = Game.player - dano;
                printf("\nDano Sofrido: %d - %d \n",Game.player+dano,dano);
                printf("Seu HP: %d  | vs |  HP Inimigo: %d\n",Game.player,Game.enemy);
                printf("\nAperte 1 para continuar\n");
                scanf("%d",&cont);
            }else if(dado>=3){
                printf("\n{ Partida %d }\nRound %d\n",Game.numMatch+1,Game.totalRound+1);
                printf("\nSEU TURNO\n");
                printf("Seu HP: %d  | vs |  HP Inimigo: %d\n",Game.player,Game.enemy);
                printf("1-[ATAQUE]\n2-[DESISTIR]\n");
                if(dado==3){
                    if(Game.player<100){
                    printf("3-[CURA]\n");
                    }
                }
                scanf("%d",&esc);
                switch(esc){
                    case 1:
                    printf("\n[ATAQUE]\n");
                    Game.enemy = Game.enemy - dano;
                    printf("\nDano Infligido: %d - %d \n",Game.enemy+dano,dano);
                    printf("\n*HP Inimigo: %d* \n",Game.enemy);
                    printf("\nAperte 1 para continuar\n");
                    scanf("%d",&cont);
                    break;
                    
                    case 2:
                    printf("\n[DESISTIR]\n");
                    printf("-FIM DE JOGO-\n");
                    printf("Seu HP: %d \n",Game.player);
                    printf("HP Inimigo: %d \n",Game.enemy);
                    printf("\nNumero de Rounds: %d \n",Game.totalRound);
                    if(Game.vit==1){
                        printf("VITORIAS: %d \n",Game.vit);
                    }else if(Game.der==1){
                        printf("DERROTAS: %d \n",Game.der);
                    }
                    abort();
                    break;
                    
                    case 3:
                    if(dado==3){
                        Game.cureCount++;
                        printf("\n [CURA] +50!\n");
                        if(Game.player==100){
                            printf("\nVida completamente cheia!\n");
                        }else{
                        printf("\nCura aplicada: %d + %d",Game.player,Game.medicine);
                        Game.player = Game.player+Game.medicine;
                        if(Game.player>100){
                            printf("\nFull Life: 100!\n");
                            Game.player = 100;
                            printf("\nHP Restaurado!: %d\n",Game.player);
                        }else{
                        printf("\nHP Restaurado!: %d\n",Game.player);
                        printf("\nAperte 1 para continuar\n");
                        scanf("%d",&cont);
                        }
                        }
                    }
                    break;
                }
            }
            if(Game.enemy<=0 && Game.totalRound ==0){
                Game.totalRound = Game.totalRound+1;
                printf("\n====================");
                printf("\n{FIM DE ROUND}\n");
                printf("\nVoce venceu o primeiro duelo!\n");
                printf("\n====================");
                Game.vit = Game.vit+1;
                Game.player = 100;
                Game.enemy = 100;
                Game.roundWin++;
                printf("\nAperte 1 para continuar\n");
                scanf("%d",&cont);
                
            }else if(Game.player <=0 && Game.totalRound ==0){
                Game.totalRound = Game.totalRound+1;
                printf("\n====================");
                printf("\n{FIM DE ROUND}\n");
                printf("\nVoce perdeu o primeiro duelo\n");
                printf("\n====================");
                Game.der = Game.der+1;
                Game.player = 100;
                Game.enemy = 100;
                Game.roundLose++;
                printf("\nAperte 1 para continuar\n");
                scanf("%d",&cont);
            }
                
                if(Game.totalRound == 1 && Game.enemy<=0){
                printf("\n====================");
                printf("\n{FIM DE ROUND}\n");
                printf("\nVoce venceu o segundo duelo!\n");
                printf("\n====================");
                Game.vit = Game.vit+1;
                Game.totalRound = Game.totalRound+1;
                Game.roundWin++;
                printf("\nAperte 1 para continuar\n");
                scanf("%d",&cont);

            }else if(Game.player<=0 && Game.totalRound == 1){
                printf("\n====================");
                printf("\n{FIM DE ROUND}\n");
                printf("\nVoce perdeu o segundo duelo\n");
                printf("\n====================");
                Game.der = Game.der+1;
                Game.totalRound = Game.totalRound+1;
                Game.roundLose++;
                printf("\nAperte 1 para continuar\n");
                scanf("%d",&cont);
            }
                
            if(Game.totalRound == 2 && Game.vit == 2){
                printf("\n=============== FIM DE PARTIDA! ================\n");
                printf("- Voce Ganhou -\n");
                printf("\nRounds: %d",Game.totalRound);
                printf("\nNumero de vitorias: %d",Game.vit);
                printf("\nNumero de Curas utilizadas: %d",Game.cureCount);
                printf("\n======================================================\n");
                Game.matchWin++;
                Game.numMatch++;
                
            }else if(Game.totalRound == 2 && Game.der == 2){
                printf("\n================ FIM DE PARTIDA! ===================\n");
                printf("- Voce Perdeu -\n");
                printf("Rounds: %d",Game.totalRound);
                printf("\nNumero de Derrotas: %d",Game.der);
                printf("\nNumero de Curas utilizadas: %d",Game.cureCount);
                printf("\n======================================================\n");
                Game.matchLost++;
                Game.numMatch++;
                
            }else if(Game.totalRound == 2 && Game.vit == 1 && Game.der == 1){
                Game.emp++;
                printf("\n=================== FIM DE PARTIDA! ==================\n");
                printf("- EMPATE -\n");
                printf("Rounds: %d",Game.totalRound);
                printf("\nNumero de empates: %d",Game.emp);
                printf("\nNumero de Curas utilizadas: %d",Game.cureCount);
                printf("\n======================================================\n");
                Game.matchDraw++;
                Game.numMatch++;
            }
                
                if(Game.totalRound==2){
                    Game.resVit += Game.vit;
                    Game.resDer += Game.der;
                    printf("\nGostaria de tentar novamente?\n1-SIM\n2-NAO\n");
                    scanf("%d",&op);
                    switch(op){
                        case 1: printf("\nReiniciando Jogo\n");
                        gameReset();
                        break;
                        
                        case 2: printf("\n[ FIM DE JOGO ]\n");
                        printf("\n======= {Resultados Gerais} =======\n");
                        printf("Partidas: %d",Game.numMatch);
                        printf("\nTotal de ROUNDS Vencidos: %d",Game.resVit);
                        printf("\nTotal de ROUNDS Perdidos: %d",Game.resDer);
                        printf("\nNumero de Vitorias por Partida: %d",Game.matchWin);
                        printf("\nNumero de Empates por Partida: %d",Game.matchDraw);
                        printf("\nNumero de Derrotas por Partida: %d",Game.matchLost);
                        printf("\nNumero de Curas utilizadas durante o jogo: %d",Game.cureCount);
                        printf("\n");
                        abort();
                        break;
                    }
                }
            }while(Game.player>0 || Game.enemy>0);
        }while(Game.totalRound<=2);
    }while(op==1);
}