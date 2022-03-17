/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: February 16, 2020
Programming Assignment: PA3
Description: Create a program that solves three tasks: 1) read integers from a file and checks if it is a multiple of 7, 11, or 13, if the sum of digits is even or odd, and if it is a prime number; 2) use linear search to check if user won the lottery or not; 3) read in words from an input file, create arrays for each type of words, and generate random sentences.
Notes: Function definition cpp file
*/
#include "PA3.h"
// function definitions
////////////////////////////////////
// TASK 1
////////////////////////////////////
/*************************************************************
 * Function: runTask1()
 * Date Created: 02/13/20
 * Date Last Modified: 02/17/20          
 * Description: This function runs task 1.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the functions called that answer and execute
 *				task 1.
*************************************************************/
void runTask1() {
	int num = 0;
	bool isM, isSE, isP;
	ifstream inputFile;
	// open a file and for each integer in the file
	string fileName = "numbers.txt";
	openInputFile(inputFile, fileName);
	// call answerIntegerQuestions()
	while (!inputFile.eof()) {
		// gets each number from each line
		inputFile >> num;
		if (inputFile.good()) {
		// answers task 1 questions and outputs the answers
		answerIntegerQuestions(num, &isM, &isSE, &isP);
		cout << "isMultiple: " << isM << ", isSumEven: " << isSE << ", isPrime: " << isP << endl;
		}
	}
	inputFile.close();
}
/*************************************************************
 * Function: openinputFile()
 * Date Created: 01/21/20
 * Date Last Modified: 02/17/20          
 * Description: This function opens file for reading in.
 * Input parameters: The ifstream file must be pass by 
 *				reference and the name of the file.
 * Returns: nothing
 * Pre: The ifstream file must be pass by 
 *				reference and the name of the file had to have 
 *            	been scanned in by the user.
 * Post: The file is opened or not and a message is displayed.
 *************************************************************/
void openInputFile(ifstream& inputFile, string iname) {
	// opens file for reading & outputs message
	inputFile.open(iname);
	if (inputFile.is_open()) {
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1);
	}
}
/*************************************************************
 * Function: answerIntegerQuestions()
 * Date Created: 02/13/20
 * Date Last Modified: 02/17/20          
 * Description: This function calls other functions to answer
 *				task 1 questions.
 * Input parameters: The number read in from the file, the
 *				bool pointers for isMultiple, isSumEven, and
 *				isPrime.
 * Returns: nothing
 * Pre: The number read in from the file, the bool pointers for
 *				isMultiple, isSumEven, and isPrime had to have 
 *            	been scanned in by the user.
 * Post: The returned bool value is assigned to correspinging
 *				variables.
 *************************************************************/
void answerIntegerQuestions(int num, bool * isMultiple, bool * isSumEven, bool * isPrime) {
	// call a function to answer the first Q
	*isMultiple = checkMultiple7OR11OR13(num);
	// call a function to answer the second Q
	*isSumEven = checkSumEven(num);
	// call a function to answer the third Q
	*isPrime = checkPrimeNumber(num);
}
/*************************************************************
 * Function: checkMultiple7OR11OR13()
 * Date Created: 02/13/20
 * Date Last Modified: 02/17/20          
 * Description: This function checks if the input number is a
 *				multiple of 7, 11, 13, or not.
 * Input parameters: The number read in from the file.
 * Returns: bool value (true or false)
 * Pre: The number read in from the file had to have been
 *            	scanned in by the user.
 * Post: The value of true or false is returned.
 *************************************************************/
bool checkMultiple7OR11OR13(int num) {
	// checks if multiple
	if (num % 7 == 0 || num % 11 == 0 || num % 13 == 0) {
		return true;
	}
	return false;
}
/*************************************************************
 * Function: checkSumEven()
 * Date Created: 02/13/20
 * Date Last Modified: 02/17/20          
 * Description: This function checks if the input number's sum
 *				is even or not (odd).
 * Input parameters: The number read in from the file.
 * Returns: bool value (true or false)
 * Pre: The number read in from the file had to have been
 *            	scanned in by the user.
 * Post: The value of true or false is returned.
 *************************************************************/
bool checkSumEven(int num) {
	int sum = 0;
	// loop that adds up the individual digits of the number
	while (num != 0) {
		sum = sum + num % 10;
		num = num / 10;
	}
	// if the value the digits add up to is even, return true
	if (sum % 2 == 0) {
		return true;
	}
	return false;
}
/*************************************************************
 * Function: checkPrimeNumber()
 * Date Created: 02/13/20
 * Date Last Modified: 02/17/20          
 * Description: This function checks if the input number is a
 *				prime number or not.
 * Input parameters: The number read in from the file.
 * Returns: bool value (true or false)
 * Pre: The number read in from the file had to have been
 *            	scanned in by the user.
 * Post: The value of true or false is returned.
 *************************************************************/
bool checkPrimeNumber(int num) {
	int i;
	// loop to see if the value can be divided by a number and have no remainder
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
////////////////////////////////////
// TASK 2
////////////////////////////////////
/*************************************************************
 * Function: runTask2()
 * Date Created: 02/14/20
 * Date Last Modified: 02/17/20          
 * Description: This function runs task 2.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the functions called that answer and execute
 *				task 2.
*************************************************************/
void runTask2() {
	int wTN, nPN = 10;
	int pN[nPN] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
	bool fWLT;
	cout << endl << "Enter this week's winning 5-digit number: ";
	cin >> wTN;
	fWLT = findWinningLotteryTicket(wTN, pN, nPN);
	if (fWLT == true) {
		cout << "You are the lucky lottery winner. You have hit the jackpot!" << endl;
	}
	else {
		cout << "Luck is not on your side. Maybe next time!" << endl;
	}
}
/*************************************************************
 * Function: findWinningLotteryTicket()
 * Date Created: 02/14/20
 * Date Last Modified: 02/17/20          
 * Description: This function uses linear search to check if
 *				the lottery numbers the player has matches
 *				this week's winning numbers or not.
 * Input parameters: The number inputed from the user, the
 *				pointer for the array of numbers the player
 *				has, and how many 5 digit numbers he has.
 * Returns: bool value (true or false)
 * Pre: The number inputed from the user, the pointer for the
 *				array of numbers the player has, and how many
 *				5 digit numbers he has had to have been
 *            	scanned in by the user.
 * Post: The value of true or false is returned.
 *************************************************************/
bool findWinningLotteryTicket(const int winningTicketNum, const int * playerNumbers,
		const int numPlayerNumbers) {
	int i;
	// loop that checks the winning number to the numbers the player has
	for (i = 0; i < numPlayerNumbers; i++) {
		if (*(playerNumbers + i) == winningTicketNum) {
			return true;
		}
	}
	return false;
}
////////////////////////////////////
// TASK 3
////////////////////////////////////
/*************************************************************
 * Function: runTask3()
 * Date Created: 02/16/20
 * Date Last Modified: 02/17/20          
 * Description: This function runs task 3.
 * Input parameters: none
 * Returns: nothing
 * Pre: nothing
 * Post: Runs the functions called that execute task 3.
*************************************************************/
void runTask3() {
	// declare variables
	ifstream inputFile;
	string fileName = "../input_words.txt";
	int numSentence;
	string sentences;
	int aS, nS, vS, pS;
	string * aArr;
	string * nArr;
	string * vArr;
	string * pArr;
	string arrName;
	int arrSize;
	string line;
	// opens file for reading in
	openInputFile(inputFile, fileName);
	inputFile >> numSentence;
	cout << endl << "WELCOME TO THE RANDOM SENTENCE C++ PROGRAM!!" << endl << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl << endl;
	cout << "WORD BANK" << endl << "----------" << endl;
	// loop that generates the word arrays
	int y = 0;
	while (y < 4) {
		inputFile >> arrName;
		inputFile >> arrSize;		
		// switch case that assigned the words to correct array if written in different order
		char firstLetter = arrName[0];
		switch (firstLetter) {
			case 'A':
				aArr = createWordsArray(inputFile, arrSize);
				aS = arrSize;
				break;
			case 'N':
				nArr = createWordsArray(inputFile, arrSize);
				nS = arrSize;
				break;
			case 'V':
				vArr = createWordsArray(inputFile, arrSize);
				vS = arrSize;
				break;
			case 'P':
				pArr = createWordsArray(inputFile, arrSize);
				pS = arrSize;
				break;
		}	
		y++;
	}
	cout << "Articles: ";
	printArray(aArr, aS);
	cout << "Nouns: ";
	printArray(nArr, nS);
	cout << "Verbs: ";
	printArray(vArr, vS);
	cout << "Prepositions: ";
	printArray(pArr, pS);
	cout << endl << "GENERATED SENTENCES" << endl << "--------------------" << endl;
	// loop that generates the number of sentences
	for (int j = 0; j < numSentence; j++) {
	 	cout << j + 1 << ".";
		generateSentence(&sentences, aArr, aS, nArr, nS, vArr, vS, pArr, pS);
	}
	inputFile.close();
	// free all dynamically allocated memory
	aArr = nullptr;
	vArr = nullptr;
	nArr = nullptr;
	pArr = nullptr;
	delete aArr;
	delete vArr;
	delete nArr;
	delete pArr;
}
/*************************************************************
 * Function: createWordsArray()
 * Date Created: 02/16/20
 * Date Last Modified: 02/17/20          
 * Description: This function reads in the words from the file
 *				and generates an array and sorts it by 
 *				alphabetical order.
 * Input parameters: The ifstream file must be pass by 
 *				reference and the size of the array.
 * Returns: the created array
 * Pre: The ifstream file must be pass by reference and the
 *				size of the array had to have been scanned
 *            	in by the user.
 * Post: The sorted array is returned by pointer notation.
 *************************************************************/
string * createWordsArray(ifstream& inFile, const int size) {
	string * arr = new string[size];
	string word;
	// loop that gets the words from the file and inputs it into the array
	for(int i = 0; i < size; i++) {
		inFile >> word;
		*(arr + i) = word;
	}
	// sorts it in alphabetical order
	insertionSortArray(arr, size);
	return arr;
}
/*************************************************************
 * Function: insertionSortVector()
 * Date Created: 02/05/20
 * Date Last Modified: 02/05/20          
 * Description: This function accepts a vector as sorts it in
 *				ascending order using insertion sort.
 * Input parameters: The vector and ofstream file must be pass 
 *				by reference.
 * Returns: nothing
 * Pre: The vector and ofstream file must be pass by 
 *				reference and scanned in by the user.
 * Post: Takes unsorted and sorted vectors and sorts them
 *				correctly and outputs data to csv file.
*************************************************************/
void insertionSortArray(string * arr, const int size) {
	int i, j;
	string currValue;
	for (i = 1; i < size; i++) {
		currValue = *(arr + i);
		j = i - 1;
		while (j >= 0 && currValue < *(arr + j)) {
			*(arr + (j + 1)) = *(arr + j); 
			j--;
		}
		*(arr + (j + 1)) = currValue;
	}
}
/*************************************************************
 * Function: printArray()
 * Date Created: 02/13/20
 * Date Last Modified: 02/17/20          
 * Description: This function prints out the array elements.
 * Input parameters: A pointer to an array and its size.
 * Returns: nothing
 * Pre: A pointer to an array and its size had to have been
 *            	scanned in by the user.
 * Post: The array elements are couted to the terminal.
*************************************************************/
void printArray(string * arr, int size) {
	int i;
	// prints out each element of the array
	for (i = 0; i < size - 1; i++) {
		cout << *(arr + i) << " ";
	}
	cout << *(arr+ i) << endl;
}
/*************************************************************
 * Function: generateSentence()
 * Date Created: 02/16/20
 * Date Last Modified: 02/17/20          
 * Description: This function generates the sentence with
 *				the words from the arrays.
 * Input parameters: A pointer to a string and the different
 *				word arrays and their corresponding sizes.
 * Returns: nothing
 * Pre:A pointer to a string and the different
 *				word arrays and their corresponding sizes had
 *            	to have been scanned in by the user.
 * Post: The sentence is couted to the terminal.
*************************************************************/
void generateSentence(string * sentence,
		const string * articlesArr, const int articlesSize,
		const string * nounsArr, const int nounsSize,
		const string * verbsArr, const int verbsSize, 
		const string * prepsArr, const int prepsSize) {
	int rN = rand() % articlesSize;
	string noun1 = "";
	string verb = "";
	string prep = "";
	string article = "";
	string noun2 = "";
	// converts the first letter of the sentence to be capital
	char first = articlesArr[rN][0];
	first -= 32;
	string output = *(articlesArr + rN);
	output[0] = first;
	// picks a random word from the array and stores it in string variables
	noun1 = *(nounsArr + (rand() % nounsSize));
	verb = *(verbsArr + (rand() % verbsSize));
	prep = *(prepsArr + (rand() % articlesSize));
	article = *(articlesArr + (rand() % prepsSize));
	noun2 = *(nounsArr + (rand() % nounsSize));
	// creates a full sentence
	*sentence = output + " " + noun1 + " " + verb 
		+ " " + prep + " " + article + " " + noun2 + "!";
	cout << " " << *sentence << endl;
}
