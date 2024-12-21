//
//  Library.hpp
//  Final Project
//
//  Created by Sam Wiiliams on 11/18/24.
//

#ifndef Library_hpp
#define Library_hpp
#include <iostream>
#include <stdio.h>
#include <fstream>

#endif /* Library_hpp */

using namespace std;

struct Game{
    string name;
    int rank;
    int playerCount[10];

};

void collectAllgame(istream& data, Game& g);
void displayAllGame(const Game All_Games[], int size);
void displayOnegame(Game g);
void sort_Games_Alphabetically(Game all_Games[], int size);
int find_game(const Game All_Games[], int size, string name);
void removeGame(Game All_Games[], int& size, string game_name);
void displayOneRankGames(const Game All_Game[], int size, int rank);
double calculateAveragePlayer(const Game& game);
int find_highest_player_count(const Game All_Games[], int size, string& name);
void filter_even_and_odd_numbers(const int playerCount[], int size, int evenNumbers[], int& evenCount, int oddNumbers[], int& oddCount);
int calculateTotalPlayerCount(const Game& game);
void tableHeader();
int menu();



