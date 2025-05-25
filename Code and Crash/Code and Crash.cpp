// Code and Crash - A simple turn-based combat system in C++
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For std::rand() and std::srand
#include <ctime>   // For std::time

int main()
{
	int choice;
	int playerHealth = 100;
	int enemyHealth = 200;
	bool playerTurn = true;

	// Seed the random number generator
	

	std::vector<std::string> actions = { "Attack", "Defend", "Special" };
    std::cout << "It's your turn, what to do?!\n\n";
	std::cout << "Your Health: " << playerHealth << "\t|\tEnemy Health: " << enemyHealth << "\n\n";
	for (int i = 0; i < actions.size(); i++)
	{
		std::cout << "\t" << i + 1 << ". " << actions[i] << "\n";
	}

	while (playerTurn)
	{
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "You chose to Attack!\n";
			std::cout << "You dealed 10 damage!\n";
			playerTurn = false; // End player's turn after an action
			break;
		case 2:
			std::cout << "You chose to Defend!\n";
			std::cout << "You blocked 5 damage!\n";
			playerTurn = false; // End player's turn after an action
			break;
		case 3:
			std::cout << "You chose to use a Special move!\n";
			std::cout << "You dealt 20 damage!\n";
			playerTurn = false; // End player's turn after an action
			break;
		default:
			std::cout << "Invalid choice! Please select a valid action.\n";
			std::cout << "It's your turn, what to do?!\n";
			break;
		}
	}
}