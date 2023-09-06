#include <vector>
#include "Deck.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>


std::vector<std::string> deck;
std::vector<std::string> playerHand;
std::vector<std::string> dealerHand;

int dealerTotal;
int playerTotal;
int playerMoney;
bool inPlay;


Deck::Deck(){
  dealerTotal = 0;
  playerTotal = 0;
  playerMoney = 1000;
  for(int i = 2; i<=10 ;i++){
      for(int j = 0; j<4;j++){
        deck.push_back(std::to_string(i));
      }
  }
  for(int i = 1; i<=4; i++){
        deck.push_back("J");
  }
  for(int i = 1; i<=4; i++){
        deck.push_back("Q");
  }
   for(int i = 1; i<=4; i++){
        deck.push_back("K");
  }
   for(int i = 1; i<=4; i++){
        deck.push_back("A");
  }
  

}

void Deck::printDeck(){
  std::cout<< "{ ";
  for(int i = 0; i<deck.size();i++){
     std::cout<<"["<<deck[i]<<"], ";
     }
      std::cout<<"} \n";
  }
  
bool Deck::checkbj(int money){
  bool output;
  if (playerTotal > 21) {
    printPlayerHand();
    std::cout<<"You Bust! Dealer wins. \n \n";
    output = false;
    playerMoney -= money;
  }  
  else if (dealerTotal >21) {
    std::cout<<"Dealer Busts! You win. \n \n";
    output = false;
    playerMoney += money;
  }
  else if(playerTotal == dealerTotal){
    std::cout<< "Stand-off\n \n";
    output = false;
  }
  else if (playerTotal <= dealerTotal){
    std::cout<< "Dealer wins!\n \n";
    output = false;
    playerMoney -= money;
  }
  else if (playerTotal >= dealerTotal){
    std::cout << "Player wins!\n \n";
    output = false;
    playerMoney += money;
  }
  playerHand.clear();
  dealerHand.clear();
  dealerTotal = 0;
  playerTotal = 0;
  return output;
}

void change_total(int num){
    playerTotal += num; 
}

void Deck::deal(){
  int random1 = rand() % deck.size();
  int random2 = rand() % deck.size();
  int random3 = rand() % deck.size();
  //START DEALER
    if(deck[random3] == "J" || deck[random3] == "Q" || deck[random3] == "K" || deck[random3] == "A"){
      if(deck[random3] == "J" || deck[random3] == "Q" || deck[random3] == "K"){
          dealerTotal += 10;
          dealerHand.push_back(deck[random3]);
      }
      else{    
           if(dealerTotal + 11 > 21 ){
             dealerTotal += 1;
             dealerHand.push_back(deck[random3]);
           }
           else{
             dealerTotal += 11;
             dealerHand.push_back(deck[random3]);
           }
      }
  }else{
      dealerTotal += std::stoi(deck[random3]);
      dealerHand.push_back(deck[random3]);
  }
  //END DEALER
  
  //START PLAYER
  if(deck[random1] == "J" || deck[random1] == "Q" || deck[random1] == "K" || deck[random1] == "A"){
        if(deck[random1] == "J" || deck[random1] == "Q" || deck[random1] == "K"){
           playerTotal += 10;
            playerHand.push_back(deck[random1]);
        }
        else{
            if(playerTotal + 11 > 21 ){
             playerTotal += 1;
             playerHand.push_back(deck[random1]);
           }
           else{
             playerTotal += 11;
             playerHand.push_back(deck[random1]);
           }
      }
  }else{
      playerTotal += std::stoi(deck[random1]);
      playerHand.push_back(deck[random1]);
  }
    if(deck[random2] == "J" || deck[random2] == "Q" || deck[random2] == "K" || deck[random2] == "A"){
        if(deck[random2] == "J" || deck[random2] == "Q" || deck[random2] == "K"){
           playerTotal += 10;
           playerHand.push_back(deck[random2]);
        }else{
            if(playerTotal + 11 > 21 ){
             playerTotal += 1;
             playerHand.push_back(deck[random2]);
           }
           else{
             playerTotal += 11;
            playerHand.push_back(deck[random2]);
           }
      }
  }else{
      playerTotal += std::stoi(deck[random2]);
      playerHand.push_back(deck[random2]);
  }
  //END PLAYER
  printDealerHand();
  printPlayerHand();
  std::cout<<"\n";
}

void Deck::player_hit(){
  bool keephit = true;
  std::string answer;
  bool invalidEntry = true;
  while(keephit){
        int random = rand() % deck.size();
        if(deck[random] == "J" || deck[random] == "Q" || deck[random] == "K" || deck[random] == "A"){
        if(deck[random] == "J" || deck[random] == "Q" || deck[random] == "K"){
           playerTotal += 10;
           playerHand.push_back(deck[random]);
        }else{
            if(playerTotal + 11 > 21 ){
             playerTotal += 1;
             playerHand.push_back(deck[random]);
           }
           else{
             playerTotal += 11;
            playerHand.push_back(deck[random]);
           }
      }
  }else{
      playerTotal += std::stoi(deck[random]);
      playerHand.push_back(deck[random]);
  }
    if(playerTotal > 21){
    break;
  }
  printPlayerHand();
  
  do{
  std::cout<<"Hit or Stand?: ";
  std::cin>> answer;
  std::cout<<"\n";

    if(answer == "hit" || answer == "Hit"){
      keephit = true;
      invalidEntry = false;
    }
    else if (answer == "stand" || answer == "Stand"){
      keephit = false;
      invalidEntry = false;
    } else {
      std::cout<<"Invalid Entry. \n";
      invalidEntry = true;
    }
    std::cout<<"\n";
  }while(invalidEntry);
}
}

void Deck::dealer_hit(){
  while(dealerTotal <= 17){
        int random = rand() % deck.size();
        if(deck[random] == "J" || deck[random] == "Q" || deck[random] == "K" || deck[random] == "A"){
        if(deck[random] == "J" || deck[random] == "Q" || deck[random] == "K"){
           dealerTotal += 10;
           dealerHand.push_back(deck[random]);
        }else{
            if(dealerTotal + 11 > 21){
             dealerTotal += 1;
             dealerHand.push_back(deck[random]);
           }
           else{
             dealerTotal += 11;
            dealerHand.push_back(deck[random]);
           }
      }
  }else{
      dealerTotal += std::stoi(deck[random]);
      dealerHand.push_back(deck[random]);
  }
  printDealerHand();
}
}



void Deck::printPlayerHand(){
  std::cout<<"Your hand: "; 
  for(int i = 0; i<playerHand.size(); i++){
    std::cout<< "[" <<playerHand[i] << "] ";
  }
  std::cout<<"\n"<<"Your total: "<<playerTotal<<"\n";
  std::cout<<"\n";
}
void Deck::printDealerHand(){
  std::cout<< "Dealer's hand: " ;
  for(int i = 0; i<dealerHand.size(); i++){
    std::cout<< "[" << dealerHand[i] << "] ";
  }
  std::cout<<"\n"<<"Dealer total: "<<dealerTotal<<"\n";
  std::cout<<"\n";
}


int Deck::getMoney(){
  return playerMoney;
}
int Deck::getPlayerTotal(){
  return playerTotal;
}
void Deck::checkSplit(){
  std::vector<std::string> secondHand;
  std::string answer = "";
  if(playerHand[0] == playerHand[1]){
    std::cout<< "Would you like to split?";
    std::cin>> answer;
    if(answer == "Yes" || answer == "yes"){
      secondHand.push_back(playerHand[0]);
    }
  }
}