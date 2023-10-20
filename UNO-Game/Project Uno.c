#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void menu()
{



    printf("\n********************************************************** Welcome To Our Game#  U.N.O  #************************************************************ \n");
    printf(" ----------------------How to play UNO: \n 1) Shuffle the cards and deal 7 cards to each player.\n");
    printf("2) Put the rest of the UNO cards in the center of the table.\n");
    printf("3) Turn over the top card from the draw pile to start the game.\n");
    printf("4) Play a card to match the color, number, or symbol on the card.\n");
    printf("5) Draw a card from the draw pile if you cant play a card.Pay attention to action and Wild cards.\n");
    printf("6) Say UNO if you only have 1 card left.\n");
    printf("7) Play your last card to win the hand.\n");
    printf("\n");
    printf("\n");
}

void main()
{
    int change_color;
    change_color=0;
     int nocard;
    char carte_table[1][3];
    char player1[10];
    char player2[10];
    char user_card[1][3];
    int n, ex,x;
    int  pl,turn;
    //TABLEUX DES CARDS
    char  les_cards [108][20]= {"v0","v1","v2","v3","v4","v5","v6","v7","v8","v9","v1","v2","v3","v4","v5","v6","v7","v8","v9",
                                "vb","vb","vi","vi","v+2","v+2","b0","b1","b2","b3","b4","b5","b6","b7","b8","b9",
                                "b1","b2","b3","b4","b5","b6","b7","b8","b9","bb","bb","bi","bi","b+2","b+2",
                                "r0","r1","r2","r3","r4","r5","r6","r7","r8","r9","r1","r2","r3","r4","r5","r6","r7","r8","r9",
                                "rb","rb","ri","ri","r+2","r+2","j0","j1","j2","j3","j4","j5","j6","j7","j8","j9","j1",
                                "j2","j3","j4","j5","j6","j7","j8","j9","jb","jb","ji","ji","j+2","j+2",
                                "+4","+4","+4","+4","jk","jk","jk","jk"
                               };
    // TABLEUX DES RANDS
    char randm[108][12];
    // jouer table
    char mj1[54][20];
    char mj2[54][20];
    int  i,nbjr1=7,nbjr2=7 ;
    int test,tour;
    char color[1][1];
    char user_card1[1][3];
    char carte_table1[3];

// sfonction pour suprimer les carte de jouer

void nettoy(char tab[][20],char cart[][4],int* nt){
int i=0,ind=-1;
while(ind == -1 && i < nt){
if(strcmp(tab[i],cart[0]) == 0){
    ind = i;
}else{
i++;
}
}
for(i=ind;i<nt-1;i++){
    strcpy(tab[i],tab[i+1]);
}
*nt--;
}

        //time
        // fonction pour donner 3 second ou jouer pour ecrire uno
 void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

// Driver code to test above function
int main()

{
    char t;
    int i=0;


    while(i < 3 && t!= 'u'){
        // delay of one second
        delay(1);
     if(kbhit()){
            t = getch();
            printf("%c\n", t);
        }
        printf("%d seconds have passed\n", i + 1);
    i++;
    }
    if(t == 'u'){
        printf("UNOOO");
}
else{

}
}

















    menu();




//printf("cartes jr1 = %i, cartes jr2 = %i",nbjr1,nbjr2);
    do
    {
        printf("-----IF YOU WANT TO PLAY  ONE VS ONE PLEASE SELECT 1 ...   IF YOU WANT TO PLAY VS MACHINE PLEASE SELECT 2------ IF YOU WANT TO EXIT PRES ANY KEY \n");
        scanf("%d",&n);

        if(n==1)
            // jouer 1
        {
            printf("HELLO PLAYER ONE PLEASE ENTER YOUR NAME:\n");
            scanf("%s",player1);
            printf("hello %s you have 7 cards start play \n",player1);
            //7 card for player 1
            srand(time(0));
            for(i=0; i<7; i++)
            {
                  do{
                x=rand()%108;

               }while( strcmp(les_cards[x],"")==0);

                printf("%s \n",les_cards[x]);
                strcpy(mj1[i],les_cards[x]);
                strcpy(les_cards[x],"");


            }


            //jouer 2
            printf("HELLO PLAYER two PLEASE ENTER YOUR NAME:\n");
            scanf("%s",player2);
            printf("hello %s you have 7 cards start play \n",player2);
            // 7 cards for player 2
            srand(time(0));
            for(i=0; i<7; i++)
            {
                     do{
                x=rand()%108;

               }while( strcmp(les_cards[x],"")==0);

                printf("%s \n",les_cards[x]);
                strcpy(mj2[i],les_cards[x]);
                strcpy(les_cards,"");
            }

            // cartes de table
            printf("this is card of table:\n");
            do
            {
                 srand(time(0));
                x=rand()%108;
                //verification des cartes de tables
            }while(strcmp(les_cards[x],"+4")==0 || strcmp(les_cards[x],"jk")==0 || strcmp(les_cards[x],"")==0 || strcmp(les_cards[x],"bi")==0 || strcmp(les_cards[x],"ji")==0 || strcmp(les_cards[x],"ri")==0||strcmp(les_cards[x],"vi")==0||strcmp(les_cards[x],"bb")==0||strcmp(les_cards[x],"rb")==0||strcmp(les_cards[x],"jb")==0||strcmp(les_cards[x],"vb")==0);



            strcpy(carte_table[0],les_cards[x]);

            printf("%s\n",carte_table[0]);

            turn=1;
            do
            {
                turn++;
                pl=turn%2;

                if(pl==0)//player 1
                {      if(change_color==1)
                                    {
                                        // if player one have no cards to play
                                        do{
                                        printf("%s you have to pick a card with the color that player one has chosen it if you dont have any card press 2 ");
                                        scanf("%s",&user_card);
                                        if(strcmp(user_card1,"2")==0)
                                        {   srand(time(0));
                                            printf("this is your new card");
                                             do{
                                                x=rand()%108;

                                               }while( strcmp(les_cards[x],"")==0);
                                                         nbjr1++;
                                                printf("%s \n",les_cards[x]);
                                                strcpy(mj2[nbjr1-1],les_cards[x]);
                                                strcpy(les_cards[x],"");
                                        }



                                        }while(color[0][0]!=user_card1[0][0] && strcmp(user_card1,"2")!=0);
                                    }


                                 test=0;i=0;

                        //cartes player verification
                    do
                    {
                        if((mj1[i][0]==carte_table[0][0]) || (mj1[i][1]==carte_table[0][1]))//color and number
                        {
                            test=1;
                        }

                            if ((strcmp(mj1[i],"jk")==0)||(strcmp(mj1[i],"+4")==0))//carte spaceal
                            {
                                test=1;

                            }


                        i++;
                                //take another an extra card
                    }while((test==0) || (i<6));


                    if(test==0){


                    do{
                    printf(" you dont have any card to play tap '2' to take another card");
                    scanf("%i",&nocard);
                    }while(nocard!=2);

                    if(nocard==2)
                    {
                        srand(time(0));
                        do{

                        x=rand()%108;
                        printf("this is your new card %s\n",les_cards[x]);

                        }while(strcmp(les_cards[x],"")==0);
                        nbjr1++;
                        strcpy(mj1[nbjr1-1],les_cards[x]);

                    }

                        }
                    printf("%s it is your turn choose one card \n",player1);
                    scanf("%s",&user_card);
                    test=0;
                    i=0;
                    //verification  des cartes de jouer avec lr table

                                    if(user_card[0][0]!= carte_table[0][0] && user_card[0][1] != carte_table[0][1] && strcmp(user_card,"jk")!=0 && strcmp(user_card,"+4")!=0)
                                    {
                                        do
                                        {
                                            printf("you cant play this card please select another card :\n");
                                            scanf("%s",&user_card);
                                    }while(user_card[0][0]!=carte_table[0][0] && user_card[0][1]!=carte_table[0][1]);
                                    }



                            //play
                                if(strcmp(user_card,"bb")==0||strcmp(user_card,"bi")==0||strcmp(user_card,"jb")==0||strcmp(user_card,"bi")==0||strcmp(user_card,"rb")==0||strcmp(user_card,"ri")==0||strcmp(user_card,"vb")==0||strcmp(user_card,"vi")==0)
                                  {
                                      nettoy(mj1,user_card,&nbjr1);
                                    do{
                                       printf("you will play another tour :\n");
                                       scanf("%s",&user_card);
                                       }while(user_card[0][0] != carte_table[0][0] && user_card[0][1] != carte_table[0][1] );

                                        nettoy(mj1,user_card,&nbjr1);
                                       strcpy(carte_table,user_card);
                                       printf("this is the new card table : %s \n",carte_table[0]);

                                  }


                                    //carte verification

                                        // +4 card
                                    if(strcmp(user_card,"+4")==0)
                                    {
                                        nettoy(mj1,user_card,&nbjr1);
                                         tour=0;
                                         strcpy(carte_table,user_card);
                                         printf("this is the new card of table:(%s) the next player will take 4 extra cards ",carte_table);

                                        srand(time(0));
                                        do{
                                                tour++;
                                        do{


                                        x=rand()%108;
                                        strcpy(mj2[nbjr2-1],les_cards[x]);
                                        }while((strcmp(les_cards[x],"")==0));
                                        }while(tour <4);
                                            }
                                            //plus 2 carte
                                            tour=0;
                                        if(strlen(user_card)==3)
                                        {
                                            nettoy(mj1,user_card,&nbjr1);
                                            strcpy(carte_table,user_card);
                                            printf("this is the new card of table : %s (the player next will take 2 extra cards )",carte_table);
                                                srand(time(0));
                                                do{
                                                         tour++;
                                            do{
                                            x=rand()%108;
                                            }while(strcmp(les_cards[x],"")==0);
                                            nbjr2++;
                                               strcpy(mj2[nbjr2-1],les_cards[x]);
                                                }while(tour < 2);

                                            //joker carte

                                        }
                                        if(strcmp(user_card,"jk")==0)
                                        {
                                            nettoy(mj1,user_card,&nbjr1);
                                            change_color=1;
                                            strcpy(carte_table,user_card);
                                            do{
                                            printf("select a color please :(v,b,r,j)");
                                            scanf("%c",&color);
                                            }while(color!="v"||color!="b"||color!="r"||color!="j");
                                            printf("the next card must have this color'%s'",color);

                                                // block cart
                                        }
                                        if(strcmp(user_card,"rb")==0||strcmp(user_card,"jb")==0||strcmp(user_card,"vb")==0||strcmp(user_card,"bb")==0)
                                        {
                                            nettoy(mj1,user_card,&nbjr1);
                                        do{
                                       printf("you will play another tour :\n");
                                       scanf("%s",&user_card);
                                       }while(user_card[0][0] != carte_table[0][0] && user_card[0][1] != carte_table[0][1] );



                                            strcpy(carte_table,user_card);
                                            printf("this is the card of table %s:\n",carte_table);

                                         }


                }


                   //************************************************************
                                                        //********************************************


                             else{

                                    //JOKER CARD
                                    if(change_color==1)
                                    {
                                        do{
                                        printf("%s you have to pick a card with the color that player one has chosen it if you dont have any card press 2 ");
                                        scanf("%s",&user_card1);
                                        if(strcmp(user_card1,"2")==0)
                                        {   srand(time(0));
                                            printf("this is your new card");
                                             do{
                                                x=rand()%108;

                                               }while( strcmp(les_cards[x],"")==0);
                                                         nbjr2++;
                                                printf("%s \n",les_cards[x]);
                                                strcpy(mj1[nbjr2-1],les_cards[x]);
                                                strcpy(les_cards[x],"");


                                        }
                                        }while(color[0][0]!=user_card1[0][0] && strcmp(user_card1,"2")!=0);

                                    }

                            //player 2 cards verification
                                         i=0;
                    do
                    {
                        if(mj2[i][0]==carte_table[0][0]||mj2[i][1]==carte_table[0][1])//color and number
                        {
                            test=1;
                        }

                            if (strcmp(user_card1,"jk")==0||strcmp(user_card1,"+4")==0)//carte spaceal
                            {
                                test=1;

                            }


                        i++;

                    }while(test==0 || i<6);


                    if(test==0){
                    // if player two have no cards to play

                    do{
                    printf(" you dont have any card to play tap '2' to take another card");
                    scanf("%i",&nocard);
                    }while(nocard!=2);
                    if(nocard==2)
                    {
                          srand(time(0));
                        do{
                        x=rand()%108;
                        printf("this is your new card %s\n",les_cards[x]);

                        }while(strcmp(les_cards[x],"")==0);

                    }

                        }

                    printf("%s it is your turn choose one card \n",player2);
                    scanf("%s",&user_card1);
                    test=0;
                    i=0;
                    //verification  des cartes de jouer avec lr table

                                    if(user_card1[0][0]!=carte_table[0][0]&&user_card1[0][1]!=carte_table[0][1])
                                    {
                                        do
                                        {
                                            printf("you cant play this card please select another card :\n");
                                            scanf("%s",&user_card1);
                                    }while(user_card1[0][0]!=carte_table[0][1]&&user_card1[0][1]!=carte_table[0][1]);
                                    }



                            //play
                                if(strcmp(user_card1,"bb")==0||strcmp(user_card1,"bi")==0||strcmp(user_card1,"jb")==0||strcmp(user_card1,"bi")==0||strcmp(user_card1,"rb")==0||strcmp(user_card1,"ri")==0||strcmp(user_card1,"vb")==0||strcmp(user_card1,"vi")==0)
                                  {
                                      do{

                                       printf("you will play another tour :\n");
                                       scanf("%s",&user_card1);
                                       nettoy(mj1,user_card,&nbjr1);
                                       } while(user_card1[0][0] != carte_table[0] && user_card1[0][1] != carte_table[1]);
                                       strcpy(carte_table,user_card1);
                                       printf("this is the new card table : %s \n",carte_table);



                                  }


                                    //carte verification

                                        // +4 card
                                    if(strcmp(user_card1,"+4")==0)
                                    {
                                        nettoy(mj1,user_card,&nbjr1);
                                         tour=0;
                                         strcpy(carte_table,user_card1);
                                         printf("this is the new card of table:(%s) the next player will take 4 extra cards ",carte_table);
                                                 srand(time(0));

                                        do{
                                        tour++;

                                        x=rand()%108;
                                        strcpy(mj1,les_cards[x]);
                                        }while(strcmp(les_cards[x],"")==0||tour<4);
                                            nbjr1 += 4;
                                            }
                                            //plus 2 carte
                                            tour=0;
                                        if(strlen(user_card1)==3)
                                            nettoy(mj1,user_card,&nbjr1);
                                        {
                                            strcpy(carte_table,user_card1);
                                            printf("this is the new card of table : %s (the player next will take 2 extra cards )",carte_table);
                                                        srand(time(0));
                                            do{
                                            tour++;


                                            x=rand()%108;
                                            strcpy(mj1,les_cards[x]);

                                            }while(strcmp(les_cards[x],"")==0||tour<2);
                                                nbjr1 += 2;


                                        }
                                           //joker carte
                                        if(strcmp(user_card1,"jk")==0)
                                        {
                                            nettoy(mj1,user_card,&nbjr1);
                                            change_color=1;
                                            strcpy(carte_table,user_card1);

                                            do{
                                            printf("select a color please :(v,b,r,j)");
                                            scanf("%c",&color);
                                            }while(color!='v'||color!='b'||color!='r'||color!='j');

                                            printf("the next card must have this color'%c'",color);


                                        }
                                        // block cart
                                        if(strcmp(user_card1,"rb")==0||strcmp(user_card1,"jb")==0||strcmp(user_card1,"vb")==0||strcmp(user_card1,"bb")==0)
                                        {

                                            do{

                                       printf("you will play another tour :\n");
                                       scanf("%s",user_card1);
                                       nettoy(mj1,user_card,&nbjr1);
                                       }while(user_card1[0][0] != carte_table[0] && user_card1[0][1] != carte_table[1]);
                                       strcpy(carte_table,user_card1);
                                            printf("this is the card of table %s:\n",carte_table);
                                               }






                    }

                                }while(nbjr1 != 0 && nbjr2 != 0);
        }


                       break;



               if(n==2) {
                        printf("wait for the next update please ;)");
                        break;
                        }
                else
                {
                    printf(" SELECT 1 OR 2 PLEASE");
                }


        printf("SELECT 1 OR 2 TO PLAY AGAIN OR PRESS ANY OTHER KEY TO EXIT");
        }while(ex==1);




return 0;
    }




