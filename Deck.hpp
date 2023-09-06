//this is for the hpp
#include <vector>
#include <string>

class Deck {
private:
  std::vector<std::string> deck;
  std::vector<std::string> playerHand;
  std::vector<std::string> dealerHand;
  int dealerTotal;
  int playerTotal;

public:
Deck();
void printDeck();
bool checkbj(int money);
void change_total(int num);
void deal();
void player_hit();
void dealer_hit();
void printPlayerHand();
void printDealerHand();
int getMoney();
int getPlayerTotal();
void checkSplit();
};

