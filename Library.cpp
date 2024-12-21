//
//  Library.cpp
//  Final Project
//
//  Created by Sam Wiiliams on 11/18/24.
//

#include "Library.hpp"
#include <iomanip>
#include <fstream>
#include <iostream>


using namespace std;

void collectAllgame(istream& data, Game& g){
    string tempName;
    
    data >> g.rank;
    data.ignore();
    getline(data, tempName, ',');
    
    g.name = tempName;
    for(int i = 0; i < 10; i++) {
        data >> g.playerCount[i];
        if(i < 9) data.ignore();
    }
}

void sort_Games_Alphabetically(Game all_Games[], int size){
    bool flag;
    do{
        flag = false;
        Game temp;
        for(int i = 0; i < size - 1; i++){
            if(all_Games[i].name > all_Games[i+1].name) {
                temp = all_Games[i];
                all_Games[i] = all_Games[i+1];
                all_Games[i+1] = temp;
                flag = true;
            }
        }
    }while(flag == true);
}

    
void displayOnegame(Game g) {
    cout << left << setw(5) << g.rank
         << left<< setw(19) << g.name
         << right << setw(5);
    
    for(int i = 0; i < 10; i++) {
        cout << setw(7) << g.playerCount[i] << "k";
    }
    cout << endl;
}
void displayAllGame(const Game All_Games[], int size) {
    tableHeader();
    for(int i = 0; i < size; i++){
        displayOnegame(All_Games[i]);
    }
}
void tableHeader(){
    cout << setw(60) << "Daily Peak Players\n" << endl;
    cout << left << setw(8) << "Rank"
         << left << setw(14) << "Title"
    << left << setw(8) << "Days:";
    
    for(int i = 1; i <= 10; i++) {
        cout << setw(8) <<  to_string(i);
    }
    cout << endl;
    
    cout << setfill('-') << setw(5) << ""
         << setw(25) << ""
         << setw(10);
    
    for(int i = 0; i < 10; i++) {
        cout << setw(10) << "";
    }
    cout << setfill(' ') << endl;
    
}


int find_game(const Game All_Games[], int size, string name) {
    for(int i = 0; i < size; i++) {
        if(All_Games[i].name == name) {
            return i;
        }
    }
    return -1;
}

int menu() {
    cout << "Choose an Option\n";
    cout << "1. Display all data\n";
    cout << "2. Search for a Specific Game\n";
    cout << "3. Sort the data\n";
    cout << "4. Remove a Game\n";
    cout << "5. Filter Data\n";
    cout << "6. Average Players for one game\n";
    cout << "7. Compare Games\n";
    cout << "8. Quit\n";
    
    int choice;
    
    do{
        cout << "Enter the number of your choice." << endl;
        cin >> choice;
    }while(choice < 1 || choice > 10);
    cin.ignore();
    return choice;
}

void removeGame(Game All_Games[], int& size, string game_name) {
    int index = find_game(All_Games, size, game_name);
    if(index != -1) {
        for(int i = index; i < size - 1; i++) {
            All_Games[i] = All_Games[i+1];
        }
        size--;
    } else {
        cout << "ERROR: Cannot remove " << game_name << ", was not found.\n";
    }
}
/*void displayOneRankGames(const Game All_Game[], int size, int rank) {
    for(int i = 0; i < size; i++) {
        if(rank == All_Game[i].rank){
            cout << rank;
        }
    }
}*/
double calculateAveragePlayer(const Game& games) {
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += games.playerCount[i];
    }
    double averagePlayerCount = static_cast<double>(sum) / 10;
    return averagePlayerCount;
}
int find_highest_player_count(const Game All_Games[], int size, string& name) {
    int index_of_name = -1;
    int highest_player_count = 0;
    for (int i = 0; i < size; i++) {
        if (All_Games[i].name == name) {
            index_of_name = i;
            break;
        }
    }
        if (index_of_name == -1) {
            return -1;
        }

        int target_total = 0;
        for (int j = 0; j < 10; j++) {
            target_total += All_Games[index_of_name].playerCount[j];
        }

        int index_of_highest_game = index_of_name;

        for (int i = 0; i < size; i++) {
            if (i != index_of_name) {
                int total_player_count = 0;
                for (int j = 0; j < 10; j++) {
                    total_player_count += All_Games[i].playerCount[j];
                }

                if (total_player_count > target_total) {
                    target_total = total_player_count;
                    index_of_highest_game = i;
                }
            }
        }

        return index_of_highest_game;
    }
void filter_even_and_odd_numbers(const int playerCount[], int size, int evenNumbers[], int& evenCount, int oddNumbers[], int& oddCount) {
    evenCount = 0;
    oddCount = 0;
    for(int i = 0; i < size; i++) {
        if(playerCount[i] % 2 == 0) {
            evenNumbers[evenCount++] = playerCount[i];
        } else {
            oddNumbers[oddCount++] = playerCount[i];
        }
    }
}

int calculateTotalPlayerCount(const Game& game) {
    int total = 0;
    for(int i = 0; i < 10; i++) {
        total += game.playerCount[i];
    }
    return total;
}
