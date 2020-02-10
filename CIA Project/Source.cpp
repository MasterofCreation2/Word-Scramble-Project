#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;



int main()
{
	//This is for the the words that would be used for the scramble. Along with the hints
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	const int MAX_GUESS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"helping","Its what you do to be a good person"},
		{"infinite","Its what goes on for ever"},
		{"decade","Every ten years is a "},
		{"crying","Its what you do when you are sad"},
		{"laughing","Its what you hear a good joke"},
		{"flying","Its fun and scary at the same time"},
		{"powerful","A measure of strength"},
		{"behold","Something that is present"},
		{"transportation","what people do when they want to go to a far away place"},
		{"looking","what people when they are interested in something"}

	};

	string guess;
	int points = 0;
	char another;

	//This for the setup of the game and the welcome and help statement are here in the
	//do statement.
	do
	{
		system("cls");
		srand(time(0));




		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);

		//Thisis for the word
		string theWORD = WORDS[choice][WORD];

		//This is for hints
		string theHINT = WORDS[choice][HINT]; 

		//this jumble around the letters in the word;
		string jumble = theWORD; 
		int length = jumble.size();
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		//This the welcome, hints, and quit lines. This tells the player what to do and how to do it.
		cout << "\t\t\tWelcome to find the word!\n\n";
		cout << "You must Unscramble the letters to make a word.\n\n";
		cout << "Enter 'hint' if you would like a hint.\n\n";
		cout << "Enter 'quit' if you would like to quit the game.\n\n";
		cout << "The scrambled message is: " << jumble;

	 
		for (int nIndex = 0; nIndex < MAX_GUESS; nIndex++)
		{
			//This is for the word you guessed
			cout << "\n\nYour guess: " << nIndex + 1 << ":";
			cin >> guess;

			//This calls the hints
			if (guess == "hint")
			{
				cout << theHINT;
				points--;
			}
			//This quits the game
			else if (guess == "quit")
			{
				cout << "\nYou have quit the game now, Have a great day.\n";
				return false;
			}
			//This is if you got the word right
			else if (guess == theWORD)
			{
				cout << "\nGreat job you got the word\n";
				points += guess.size();
				break;
			}
			//This is if you didn't get the words right
			else
			{
				cout << "sorry, that is the wrong word";
			}
			
			
		}
		//This displays points the player has in total
		cout << "\n\nYour total points: " << points;
		//This allows the player to play again.
		cout << "\n\n\nWould you like to play again? (y/n): ";
		cin >> another;
	} while (another == 'y' || another == 'Y');


	system("cls");
	cout << "Thanks for playing!";
	
		

	
		
	return 0;
 }
