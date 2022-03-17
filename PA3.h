#ifndef PA3_H
#define PA3_H
/*
Name: Milee Owen
Class: CPSC 122, Spring 2020
Date: February 16, 2020
Programming Assignment: PA3
Description: Create a program that solves three tasks: 1) read integers from a file and checks if it is a multiple of 7, 11, or 13, if the sum of digits is even or odd, and if it is a prime number; 2) use linear search to check if user won the lottery or not; 3) read in words from an input file, create arrays for each type of words, and generate random sentences.
Notes: Function prototypes and header file
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
using namespace std;
// task 1
void runTask1();
void openInputFile(ifstream&, string);
void answerIntegerQuestions(const int num, bool *, bool *, bool *);
bool checkMultiple7OR11OR13(int);
bool checkSumEven(int);
bool checkPrimeNumber(int);
// task 2
void runTask2();
bool findWinningLotteryTicket(int, const int *, const int);
// task 3
void runTask3();
string * createWordsArray(ifstream&, const int);
void insertionSortArray(string *, const int);
void printArray(string *, int);
void generateSentence(string *, const string *, const int, const string *, const int, const string *, const int, const string *, const int);
#endif
