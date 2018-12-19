#define DECKSIZE 92
#define INITHAND 7      /* initial hand dealt (7 in standard Uno rules) */
#define CARDTOP 6
#define CARDLINES 7
#define CARDLEFT 2

/* Constants for each of the card values, which also correspond to their
 * char values to be displayed */
enum Number { ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
       SKIP, DRAWTWO = 68};

/* Color constants
 * DEF is the standard dialog color pair
 * UNO is used for the Uno tag in the player stats
 * WHITE is for Wilds, and a couple other things */
enum Color { RED = 1, BLUE, GREEN, YELLOW};

typedef struct {
    char num;
    int col;
} Card;


typedef struct Cardname {
    struct {
        char s[50];
        char c;
        
    }num;
    char col[50];
}Cardname;

/* players' hands
 * Each element contains a pointer to a card,
 * as well as a link to the next card in the player's hand. */
typedef struct Handcard {
    Card const *card;
    struct Handcard *link;
}Handcard;


struct scores
{
	int player_score;
	char player_name[13];
};



void clean(Handcard *); /* Frees up a linked list from tail to head end, then sets head to NULL */
void shuffle(Handcard *); /* Shuffle whatever pile has been passed to it, starting at head */
int length(Handcard *);  /* Get the length of the hand passed to it */
struct Cardname getcardname( Card *card);  /* Gets the name of the card as strings */ 
void sort_scores(struct scores st[],int size);

/* draw *
 * A more complicated function. Draws a card from the draw pile into
 * the player's hand, and also handles reshuffling deck if draw pile is empty.
 * Returns 1 if a card is successfully drawn, 0 if not */
 
