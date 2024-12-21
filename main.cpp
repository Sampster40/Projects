//
//  main.cpp
//  Final Project
//
//  Created by Sam Wiiliams on 11/18/24.
//

#include <iostream>
#include <iomanip>
#include "Library.hpp"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    Game games[10];
    int num_games = 10;
    int choice;
    int position;
    int gameCount = 0;
    int rank;
    int playerCount = 0;
    
    
    string fileName, source, game;
    ifstream gameFile;
    
    cout << "Welcome to the Game Program\n";
    do{
        cout << "Enter the filename you would like to open\n";
        cin >> fileName;
        gameFile.open(fileName);
    }while(!gameFile.is_open());
    cout << "File Opened." << endl;
    string line;
    getline(gameFile, line);
    cout << line << endl;
    while(getline(gameFile, line) && gameCount < 10) {
        stringstream lineStream(line);
        if(lineStream.str().empty()){
            continue;
        }
        collectAllgame(lineStream, games[gameCount]);
        gameCount++;
    }
    gameFile.close();
    
    do{
        choice = menu();
        switch(choice){
            case 1: {
                displayAllGame(games, num_games);
                break;
            }
            case 2: {
                cout << "Enter game to search for: ";//Will add code later
                getline(cin, game);
                position = find_game(games, num_games, game);
                if(position != -1) {
                    tableHeader();
                    displayOnegame(games[position]);
                } else {
                    cout << "Error: " << game << " not found.\n";
                }
                break;
            }
            case 3: {
                sort_Games_Alphabetically(games, num_games);
                displayAllGame(games, num_games);
                break;
            }
            case 4: {
                cout << "Enter a games name to remove its data.\n";
                getline(cin, game);
                removeGame(games, num_games, game);
                displayAllGame(games, num_games);
                break;
            }
            case 5: {
                cout << "Which game's player count would you like to filter by even and odd numbers?\n";
                getline(cin, game);
                
                cout << "User entered '" << game << "'" << endl;
                
                int gameIndex = -1;
                for(int i = 0; i < num_games; i++) {
                    if(games[i].name == game) {
                        gameIndex = i;
                        break;
                    }
                }
                int evenNumbers[10], oddNumbers[10];
                int evenCount, oddCount;
                filter_even_and_odd_numbers(games[gameIndex].playerCount, 10, evenNumbers, evenCount, oddNumbers, oddCount);
                cout << "Player counts for " << games[gameIndex].name << ":\n";
                cout << "Even Numbers: ";
                for(int i = 0; i < evenCount; i++) {
                    cout << evenNumbers[i] << "k ";
                }
                cout << endl;
                cout << "Odd Numbers: ";
                for(int i = 0; i < oddCount; i++) {
                    cout << oddNumbers[i] << "k ";
                }
                cout << endl << endl;
                break;
            }
            case 6: {
                cout << "Enter game to get average player count of your desired game: " << endl;
                getline(cin, game);
                position = find_game(games, num_games, game);
                if(position != -1) {
                    cout << "The average player count for the game " << games[position].name << " is " <<  calculateAveragePlayer(games[position]) << "k" <<endl << endl;
                    
                } else {
                    cout << "Error " << game << " could not be found\n";
                }
                break;
            }
            case 7: {
                cout << "What game would you like to compare player count for?\n";
                getline(cin, game);
                
                int userGameIndex = -1;
                for(int i = 0; i < num_games; i++) {
                    if(games[i].name == game) {
                        userGameIndex = i;
                        break;
                    }
                }
                if(userGameIndex == -1) {
                    cout << "Game was not found" << endl;
                } else{
                    int highestGameIndex = 0;
                    int highestTotalPlayerCount = calculateTotalPlayerCount(games[0]);
                    for(int i = 1; i < num_games; i++) {
                        int currenTotal = calculateTotalPlayerCount(games[i]);
                        if(currenTotal > highestTotalPlayerCount) {
                            highestTotalPlayerCount = currenTotal;
                            highestGameIndex = i;
                        }
                    }
                    int userGameTotal = calculateTotalPlayerCount(games[userGameIndex]);
                    int highestGameTotal = calculateTotalPlayerCount(games[highestGameIndex]);
                        cout << games[userGameIndex].name << " has " << userGameTotal << "k total players vs. " << games[highestGameIndex].name << " with " << highestGameTotal  << "k total players in the last 10 days."<<  endl;
                    cout << "In the last 10 days the game with the highest total player count was " << games[highestGameIndex].name << " with total player count " << highestGameTotal << "k" << endl << endl;
                    
                }
            }
                break;
            case 8: {
                cout << "Thank you for using this program. <3\n";
                break;
            }
        }
    }while(choice != 8);
    
    return 0;
            
    }
    
    
    
    

