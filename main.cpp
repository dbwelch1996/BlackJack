#include <iostream>
#include <vector>
#include "Deck.hpp"

int main() {
std::string move;
int playerBet;
srand(time(NULL));
Deck hand;
//start of outer while loop
//hand.printDeck();
do{
  if (hand.getMoney()<=0) {
    std::cout<<"You ran out of money! \n";
    break;
  }
  std::cout<< "How much money would you like to bet? You currently have $" << hand.getMoney() << ": "; 
  std::cin>> playerBet;
  std::cout<< "\nYou bet $" << playerBet<<"\n \n";
do{
  hand.deal();
  std::cout << "Hit or Stand?: ";
  std::cin >> move;
  std::cout<<"\n";
  if(move == "hit" || move == "Hit"){
    hand.player_hit();
  }
  if(hand.getPlayerTotal() <= 21){
    hand.dealer_hit();
  }
  }while(hand.checkbj(playerBet));



}while(true);
  //prompt user if they want to bet more 
}
