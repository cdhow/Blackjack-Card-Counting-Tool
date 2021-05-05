#include <iostream>
#include <sstream>

/*
 * Tool used for counting cards in online blackjack.
 * It takes the card numbers each round as input and 

*/

int getCardsCount(int card_num)
{

    if (card_num == 1) {
        // Ace
        return -1;
    }

    if (card_num < 7) {
        return 1;
    }

    if (card_num > 9) {
        return -1;
    }

    return 0;

}

/*
 * Returns the count of the current round and updates the remaing cards.
 */
int BJRound(int& remaining_cards)
{
    std::string input;
    getline(std::cin, input); // User inputs the cards in the round separated by spaces.
    std::istringstream iss(input);
    int temp, count = 0;
    while(iss >> temp)
    {
        count += getCardsCount(temp);
     
        remaining_cards--; // Current deck size is decreasing.
    }

    return count;
}


int main()
{
    std::cout << "How to use:\n"
              << "Each round enter the cards on the table (10 for face cards and 1 for ACE)\n";

    // Number decks.
    int decks = 6;
    std::cout << "Number of decks:\n";
    std::cin >> decks;
    std::cout << std::endl;

    // Remaining cards in shoe. (true count is running_count/ (remaining_cards/52))
    int remaining_cards = decks * 52;

    int running_count = 0;
    int true_count = 0;


    do {
    
        while (remaining_cards != 0) {

            running_count += BJRound(remaining_cards);

            // True count is the running count divided by the number of remaing decks.
            true_count = running_count / (remaining_cards / 52);

            std::cout << "Running count = " << running_count << " True count = " << true_count << std::endl;
        }
        
        std::cout << "All packs have been used - Restarting\n";

        // All packs have been used, restart.
        remaining_cards = 6 * 52; // Assuming number of decks used is 6 (can change).

        true_count = 0;
        running_count = 0;

    } while (true);




    return 0;
}