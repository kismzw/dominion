#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void push(int,int**, int*,int);
int pop(int**, int*,int);

int main(void){
    const int num_players = 2;
    const int v = 3;
    const int c = 1;
    const int t = 3;
    const int a = 10;
    const int max_deck = 200;
    int **victory_cards;
    int **curse_cards;
    int **treasure_cards;
    int **action_cards;
    int **victory_cards_num;
    int **curse_cards_num;
    int **treasure_cards_num;
    int **action_cards_num;
    int **deck;
    int **hands;
    int **discard;

    victory_cards = malloc(sizeof(int*)*num_players);
    victory_cards_num = malloc(sizeof(int*)*num_players);
    curse_cards = malloc(sizeof(int*)*num_players);
    curse_cards_num = malloc(sizeof(int*)*num_players);
    treasure_cards = malloc(sizeof(int*)*num_players);
    treasure_cards_num = malloc(sizeof(int*)*num_players);
    action_cards = malloc(sizeof(int*)*num_players);
    action_cards_num = malloc(sizeof(int*)*num_players);
    deck = malloc(sizeof(int*)*num_players);
    hands = malloc(sizeof(int*)*num_players);
    discard = malloc(sizeof(int*)*num_players);
    for(int i = 0; i < num_players;i++){
        victory_cards[i]=malloc(sizeof(int)*v);
        victory_cards_num[i]=malloc(sizeof(int)*v);
        curse_cards[i]=malloc(sizeof(int)*c);
        curse_cards_num[i]=malloc(sizeof(int)*c);
        treasure_cards[i]=malloc(sizeof(int)*t);
        treasure_cards_num[i]=malloc(sizeof(int)*t);
        action_cards[i]=malloc(sizeof(int)*a);
        action_cards_num[i]=malloc(sizeof(int)*a);
        deck[i]=malloc(sizeof(int)*max_deck);
        hands[i]=malloc(sizeof(int)*max_deck);
        discard[i]=malloc(sizeof(int)*max_deck);
    }


    for(int i = 0; i < num_players;i++){
        free(victory_cards[i]);
        free(victory_cards_num[i]);
        free(curse_cards[i]);
        free(curse_cards_num[i]);
        free(treasure_cards[i]);
        free(treasure_cards_num[i]);
        free(action_cards[i]);
        free(action_cards_num[i]);
        free(deck[i]);
        free(hands[i]);
        free(discard[i]);
    }
    free(victory_cards);
    free(victory_cards_num);
    free(curse_cards);
    free(curse_cards_num);
    free(treasure_cards);
    free(treasure_cards_num);
    free(action_cards);
    free(action_cards_num);
    free(deck);
    free(hands);
    free(discard[i]);
    return 0;
}

void push(int value, int** stack,int *num_cards,int turn){
    for (int i = 0; i < *num_cards; i++){
        stack[turn][i+1] = stack[turn][i];
    }
    stack[turn][i] = value;
    *num_cards++;
}

int pop(int** stack,int *num_cards,int turn){
    if(num_cards==0){
        return -1;
    }
    else{
        *num_cards --;
        return stack[turn][0];
    }
}