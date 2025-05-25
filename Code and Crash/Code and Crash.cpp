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

	// Seed the random number generator
	srand(time(0));

	while (playerHealth > 0 && enemyHealth > 0)
	{
		int playerDamage = rand() % 5 + 15; // Random damage between 15 and 20
		int playerBlock = rand() % 5 + 10; // Random block between 10 and 15
		int playerSpecial = rand() % 10 + 30; // Random special damage between 30 and 40

		int enemyDamage = rand() % 5 + 10; // Random enemy damage between 10 and 15
		int enemyBlock = rand() % 5 + 5; // Random enemy block between 5 and 10

		std::vector<std::string> actions = { "Attack", "Defend", "Special" };
		std::cout << "\nIt's your turn, what to do?!\n\n";
		std::cout << "Your Health: " << playerHealth << "\t|\tEnemy Health: " << enemyHealth << "\n\n";
		for (int i = 0; i < actions.size(); i++)
		{
			std::cout << "\t" << i + 1 << ". " << actions[i] << "\n";
		}

		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "You chose to Attack!\n";
			std::cout << "You dealt " << playerDamage << " damage!\n";
			break;
		case 2:
			std::cout << "You chose to Defend!\n";
			std::cout << "You blocked " << playerBlock << " damage!\n";
			break;
		case 3:
			std::cout << "You chose to use a Special move!\n";
			std::cout << "You dealt " << playerSpecial << " damage!\n";
			break;
		default:
			std::cout << "Invalid choice! Please select a valid action.\n";
			std::cout << "It's your turn, what to do?!\n";
			continue; // Prompt for input again
		}

		if (enemyHealth > 0)
		{
			std::cout << "\nEnemy's turn!\n";
			int enemyChoice = rand() % 2 + 1; // Randomly choose an action for the enemy
			switch (enemyChoice)
			{
			case 1:
				std::cout << "Enemy chose to Attack!\n";
				std::cout << "Enemy dealt " << enemyDamage << " damage!\n";
				if (choice == 1)
				{
					enemyHealth -= playerDamage;
				}
				else if (choice == 3)
				{
					enemyHealth -= playerSpecial;
				}
				if (choice == 2) // If player defended
				{
					playerHealth -= std::max(0, enemyDamage - playerBlock); // Reduce player health by the damage minus the block amount
				}
				else // If player did not defend
				{
					playerHealth -= enemyDamage;
				}
				break;
			case 2:
				std::cout << "Enemy chose to Defend!\n";
				std::cout << "Enemy blocked " << enemyBlock << " damage!\n";
				if (choice == 1) // If player attacked
				{
					std::cout << "Enemy blocked your attack!\n";
					enemyHealth -= std::max(0, playerDamage - enemyBlock); // Reduce enemy health by the damage minus the block amount
				}
				else if (choice == 3) // If player used special
				{
					std::cout << "Enemy blocked your special move!\n";
					enemyHealth -= std::max(0, playerSpecial - enemyBlock); // Reduce enemy health by the special damage minus the block amount
				}
				break;
			}
		}
	}

	if (playerHealth <= 0)
	{
		std::cout << "\nYou have been defeated! Code crashed... \n";
	}
	else if (enemyHealth <= 0)
	{
		std::cout << "\nYou defeated the enemy! Code survives another day!!\n";
	}

	return 0;
}