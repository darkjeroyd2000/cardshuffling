#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//prototypes
void shuffle(unsigned int wDeck[][FACES]); //shuffling modifies deck
void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]); //dealing doesn't modify the arrays

int main(void)
{
	const char *suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" }; //initialization of suit array
	
	const char *face[FACES] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	unsigned int deck[SUITS][FACES] = { 0 }; //deck array initialization

	srand((unsigned int)(time(NULL))); //seed random-number generator

	shuffle(deck); // call to shuffle function to shuffle the deck
	deal(deck, face, suit); //call to deal function to deal the deck

	_getch();
	return 0;
}

void shuffle(unsigned int wDeck[][FACES])
{
	size_t row;
	size_t column;
	size_t card;

	for (card = 1; card <= CARDS; ++card)
	{
		do 
		{
			row = rand() % SUITS;
			column = rand() % FACES;
		} 
		while (wDeck[row][column] != 0);
		{
		wDeck[row][column] = card;
		}
	}
}

void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[])
{
	size_t row;
	size_t column;
	size_t card;

	for (card = 1; card <= CARDS; ++card)
	{
		for (row = 0; row < SUITS; ++row)
		{
			for (column = 0; column < FACES; ++column)
			{
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t'); //2-column format
				}
			}

		}

	}
}
