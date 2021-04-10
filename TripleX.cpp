#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Epic welcome messages to the terminal
    std::cout << "\n\nYou are a magic user trying to mix a level " << Difficulty;
    std::cout << " potion \nYou need to mix the correct number of ingredients to make a potion...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product
    std::cout << std::endl;
    std::cout << "+ There are three ingredients";
    std::cout << "\n+ The ingredients add up to give: " << CodeSum;
    std::cout << "\n+ And multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Check the answer
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You have successfully crafted the potion! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You failed to craft the potion and it exploded... Try again... ***";
        return false;
    }

}

int main()
{   
    srand(time(NULL)); // New random sequence based on time of the day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clear errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        else 
        {
            return 0;
        }
    }
    std::cout << "\n*** Good job! You have finished crafting the portions! Sugoi uwu! ***\n";
    return 0;
}

