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
	srand(time(0));


	int damage = rand() % 5 + 15; // Random damage between 15 and 20
	int block = rand() % 5 + 5; // Random block between 5 and 10
	int special = rand() % 10 + 20; // Random special damage between 20 and 30

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
			std::cout << "You dealed " << damage << " damage!\n";
			playerTurn = false; // End player's turn after an action
			break;
		case 2:
			std::cout << "You chose to Defend!\n";
			std::cout << "You blocked " << block << " damage!\n";
			playerTurn = false; // End player's turn after an action
			break;
		case 3:
			std::cout << "You chose to use a Special move!\n";
			std::cout << "You dealt " << special << " damage!\n";
			playerTurn = false; // End player's turn after an action
			break;
		default:
			std::cout << "Invalid choice! Please select a valid action.\n";
			std::cout << "It's your turn, what to do?!\n";
			break;
		}
	}

	return 0;
}