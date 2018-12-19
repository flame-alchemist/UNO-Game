#include "uno_header.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
struct Cardname getcardname( Card *card)
{
	struct Cardname cardname;
    /* set color string */
    switch(card->col) {
    case RED:
        strcpy(cardname.col,"Red ");
        break;
    case BLUE:
        strcpy(cardname.col ,"Blue ");
        break;
    case GREEN:
        strcpy(cardname.col , "Green ");
        break;
    case YELLOW:
        strcpy(cardname.col ,"Yellow ");
        break;
    
    }


    /* ...and now name string */
    switch(card->num) {
    
    case SKIP:
        strcpy(cardname.num.s , "Skip");cardname.num.c ='\0';
        break;
    case DRAWTWO:
        strcpy(cardname.num.s , "Draw Two");cardname.num.c ='\0';
        break;
    
    default:
        cardname.num.c = card->num;strcpy(cardname.num.s , "\0");
        break;
    }

    return cardname;
}


/* clean *
 * Frees up a linked list from tail to head end, then sets head to NULL */
void clean(Handcard *head)
{
    if(head == NULL) /* don't try cleaning a null list */
        return;

     Handcard *p;
    while(head->link != NULL) {
        for(p=head; p->link->link != NULL; p = p->link)
            ;
        free(p->link);
        p->link = NULL;
    }
    free(head);
    head = NULL;
}


/* length *
 * Get the length of the hand passed to it */
int length(Handcard *head)
{
    Handcard *current;
    int count = 0;

    if(head == NULL)
        return 0;
    for(current = head; current != NULL; current = current->link)
        count++;

    return count;
}
void shuffle(struct Handcard *head)
{
    int swap, i;
    struct Handcard *p, *swapcard;
    Card const *temp;

    if(head == NULL)
        return;

	srand(time(NULL));    
//printf("%d",rand());
    for(p = head; p ->link!= NULL; p = p->link) 
    {
    	
        swap = (rand() % (length(head)));   /* index of swap card */
        temp = p->card;
        //if swap index is 0,it is not practically feasible to shuffle.Or,shiffling cannot be done.
        /*if(swap==0)

        { struct Handcard *t=(struct Handcard*)malloc(sizeof(struct Handcard));

            for(p=head;p->link!=NULL;p=p->link);
                *t=*p;


            for(p=head;p->link->link!=NULL;p=p->link)
            {
                *(p->link)=*p;

            }
            *head=*t;
            free(t);
        }*/
        for(i=0, swapcard=head; i<swap; i++)    /* walk to swapcard */
            swapcard = swapcard->link;
        p->card = swapcard->card;               /* swap    */
        swapcard->card = temp;                  /* addresses  */
    }
}



/*Sorts the player's scores in descending order*/
void sort_scores(struct scores st[],int size)
{
	
	struct scores temp;
	int i,j;
	for(i=1;i<size;i++)
	{
		temp=st[i];
		j=i-1;
		while(j>=0 && st[j].player_score<temp.player_score)
		{
			st[j+1] = st[j];
			j=j-1;
		}
	st[j+1]=temp;
	}
	printf("-------------------------------\n");
	printf("LEADERBOARDS\n");
	for(i=0;i<size;i++)
		printf("Player Name: %s	Player Score :%d\n" , st[i].player_name , st[i].player_score);




}








