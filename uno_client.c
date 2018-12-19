#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "uno_header.h"
const Card deck[] = {
    { ZERO, RED },
    { ONE, RED },
    { ONE, RED },
    { TWO, RED },
    { TWO, RED },
    { THREE, RED },
    { THREE, RED },
    { FOUR, RED },
    { FOUR, RED },
    { FIVE, RED },
    { FIVE, RED },
    { SIX, RED },
    { SIX, RED },
    { SEVEN, RED },
    { SEVEN, RED },
    { EIGHT, RED },
    { EIGHT, RED },
    { NINE, RED },
    { NINE, RED },
    //{ REVERSE, RED },
    //{ REVERSE, RED },
    { SKIP, RED },
    { SKIP, RED },
    { DRAWTWO, RED },
    { DRAWTWO, RED },
    { ZERO, BLUE },
    { ONE, BLUE },
    { ONE, BLUE },
    { TWO, BLUE },
    { TWO, BLUE },
    { THREE, BLUE },
    { THREE, BLUE },
    { FOUR, BLUE },
    { FOUR, BLUE },
    { FIVE, BLUE },
    { FIVE, BLUE },
    { SIX, BLUE },
    { SIX, BLUE },
    { SEVEN, BLUE },
    { SEVEN, BLUE },
    { EIGHT, BLUE },
    { EIGHT, BLUE },
    { NINE, BLUE },
    { NINE, BLUE },
    //{ REVERSE, BLUE },
    //{ REVERSE, BLUE },
    { SKIP, BLUE },
    { SKIP, BLUE },
    { DRAWTWO, BLUE },
    { DRAWTWO, BLUE },
    { ZERO, GREEN },
    { ONE, GREEN },
    { ONE, GREEN },
    { TWO, GREEN },
    { TWO, GREEN },
    { THREE, GREEN },
    { THREE, GREEN },
    { FOUR, GREEN },
    { FOUR, GREEN },
    { FIVE, GREEN },
    { FIVE, GREEN },
    { SIX, GREEN },
    { SIX, GREEN },
    { SEVEN, GREEN },
    { SEVEN, GREEN },
    { EIGHT, GREEN },
    { EIGHT, GREEN },
    { NINE, GREEN },
    { NINE, GREEN },
    //{ REVERSE, GREEN },
    //{ REVERSE, GREEN },
    { SKIP, GREEN },
    { SKIP, GREEN },
    { DRAWTWO, GREEN },
    { DRAWTWO, GREEN },
    { ZERO, YELLOW },
    { ONE, YELLOW },
    { ONE, YELLOW },
    { TWO, YELLOW },
    { TWO, YELLOW },
    { THREE, YELLOW },
    { THREE, YELLOW },
    { FOUR, YELLOW },
    { FOUR, YELLOW },
    { FIVE, YELLOW },
    { FIVE, YELLOW },
    { SIX, YELLOW },
    { SIX, YELLOW },
    { SEVEN, YELLOW },
    { SEVEN, YELLOW },
    { EIGHT, YELLOW },
    { EIGHT, YELLOW },
    { NINE, YELLOW },
    { NINE, YELLOW },
    //{ REVERSE, YELLOW },
    //{ REVERSE, YELLOW },
    { SKIP, YELLOW },
    { SKIP, YELLOW },
    { DRAWTWO, YELLOW },
    { DRAWTWO, YELLOW },
    //{ WILD, WHITE },
    //{ WILD, WHITE },
    //{ WILD, WHITE },
    //{ WILD, WHITE },
    //{ PLUSWILD, WHITE },
    //{ PLUSWILD, WHITE },
    //{ PLUSWILD, WHITE },
    //{ PLUSWILD, WHITE }
};


void main()
{
	Handcard *pile = NULL;       /* head of draw pile (linked list) */
	Handcard *discard;		/* head of discard pile (linked list) */
	Handcard *p2;
	Handcard *plcard; /* selected card in player's hand */
    	Handcard *p = NULL;      /* the generic Handcard pointer */
    	Cardname cardname;
    	/* Defaults for parameters */
    
    	int winscore = 125;
    	int i;
	
	printf("Welcome to UNO, THE ULTIMATE CARD GAME! \n");
	printf("______________________________\n");
	printf("How many players?(2-10)\n");

	int plrs;	
	scanf("%d",&plrs);

	Handcard *pl[plrs];      /* heads of players' hands (linked lists) */
    	char *plname[plrs];             /* players' names */
    	int plscore[plrs];              /* Players' scores */
    	int uno[plrs]; 

	printf("Note : Maximum number of characters the name can have is 12\n");
    	for(i=0; i<plrs; i++) 
    	{
        plscore[i] = 0;
        plname[i] = (char *) calloc(13, sizeof(char));
       	printf("Player %d enter your name :\n",i+1);
        scanf("%s",(plname[i]));
    	}


	for(i=0;i<plrs;i++)
	{
		printf("Player %d:%s\n",i+1,plname[i]);
	}
	
	printf("\n");
	printf("LET'S BEGIN THE GAME!!\n");
	
	//Creating the pile of cards

    
	pile = (struct Handcard *) malloc(sizeof(struct Handcard));
    	p = pile;
    	for(i=0; i<DECKSIZE; i++)
     	{
        p->card = &deck[i];
        if(i < DECKSIZE-1)
            p->link = (struct Handcard *) malloc(sizeof(struct Handcard));
        else
            p->link = NULL;
            p = p->link;
    	}

    	shuffle(pile);


    	for(int i=0;i<plrs;i++)
    	{
    	pl[i]=(struct Handcard*)malloc(sizeof(struct Handcard));
    	pl[i]=NULL;
    	}


    	for(int j=0;j<INITHAND;j++)
    	for(int i=0;i<plrs;i++)
    	{
    	   plcard=(struct Handcard*)malloc(sizeof(struct Handcard));
    	   plcard->card=pile->card;
    	   plcard->link=pl[i];
    	   pl[i]=plcard;
    	   p = pile;        
    	   pile = pile->link; 
           free(p);                                                  
  	} 
	
	int f2=0;
   
	//Printing the player's cards
	Handcard *temp;
    	for(int i=0;i<plrs;i++)
    	{
    	printf("\n\n%s's Cards\n",plname[i]);
    	temp=pl[i];
    	while(temp!=NULL)
    	{
    		cardname=getcardname(temp->card);
    		printf("%s %c %s\n",cardname.num.s,cardname.num.c,cardname.col);
    		temp=temp->link;
    	}

    	}
	p2=(Handcard*)malloc(sizeof(Handcard));
    	p2->card=pile->card;
  	p2->link=NULL;
  	p=pile;
  	pile=pile->link;
  	free(p);
  	
	int flag=0;

    //The Game Begins
    do
    {	
    	Handcard *prev;
    	
   		for(i=0;i<plrs;)
   		{	f2=0;
    		cardname=getcardname(p2->card);  
    		printf("\tCURRENT PLAYING CARD\n");
   	 	printf("\t\t%s %c %s\n",cardname.num.s,cardname.num.c,cardname.col); 
    		printf("%s's turn\n",plname[i]);
    		if((strcmp(cardname.num.s,"Skip")==0))
    				{	
    					temp=pl[(i+1)%plrs];
    					if (i!=plrs-1)
    					{
    						printf("Player %d has been skipped\n",(i+1));
    					}
    					else
							printf("Player %d has been skipped\n",((i+1)%plrs));
    				}
    		else if((strcmp(cardname.num.s,"Draw Two")==0))
    		{

    			temp=pl[i];

    			Handcard *t1=(Handcard*)malloc(sizeof(Handcard));
    			t1->card=pile->card;
    			pile=pile->link;
    			t1->link=temp;
    			Handcard *t2=(Handcard*)malloc(sizeof(Handcard));
    			t2->card=pile->card;
    			t2->link=t1;
    			

    			pl[i]=t2;

    					temp=pl[(i+1)%plrs];
    					if (i!=plrs-1)
    					{
    						printf("Player %d has drawn 2 cards \n",(i+1));
    					}
    					else
							printf("Player %d has drawn two cards\n",((i+1)%plrs));


    		}
    		else
    			temp=pl[i];
    		while(temp!=NULL)
    		{
    			Cardname cardname2;
    			cardname2=getcardname(temp->card);
    			
    				
    			if((strcmp(cardname2.col,cardname.col)==0) || ((strcmp(cardname2.num.s,cardname.num.s)==0)&&(cardname2.num.c==cardname.num.c)))
    			{	
    				Handcard *temp2=(Handcard *)malloc(sizeof(Handcard));
    				temp2->card=temp->card;
    				temp2->link=p2;
    				p2=temp2;
    			
    				if((strcmp(cardname2.col,cardname.col)==0))
    					plscore[i]+=25;
    				else if((strcmp(cardname2.num.s,cardname.num.s)==0)&&(cardname2.num.c==cardname.num.c))
    					plscore[i]+=25;
    				else 
    					plscore[i]+=50;
					discard=temp;
    				if(discard==pl[i])
    					pl[i]=pl[i]->link;
    				else
    				{
    					prev->link=temp->link;
    				}
    				
    			}
    			prev=temp;
    			temp=temp->link;
    		}

    		//displaying player cards again
    		Handcard *temp3;Cardname cardname3;
    		temp3=pl[i];
    		

    		while(temp3!=NULL)
    		{	
    				
    			cardname3=getcardname(temp3->card);
    			printf("%s %c %s\n",cardname3.num.s,cardname3.num.c,cardname3.col);

    			temp3=temp3->link;
    	}
    	
			if(plscore[i]>=winscore)
    		{
    			uno[i]=1;
    			flag=1;
				goto label;
    		}	
    		i++;
    	}
		label:printf("");
	}while(!flag);
    for(i=0;i<plrs;i++)
    {
    	if(uno[i]==1)
    		printf("Player %s has reached uno!\n",plname[(i)]);
    		
    }
 	printf("SCORES:\n");
 	for(int i=0;i<plrs;i++)
	{
 		printf("Player Name: %s	Player Score: %d\n",plname[i] , plscore[i]);
	}
	struct scores st[plrs];
	for(i=0;i<plrs;i++)
	{
		st[i].player_score = plscore[i];
		strcpy(st[i].player_name,plname[i]);
		
	}
	
	sort_scores(st , plrs);
	
}
