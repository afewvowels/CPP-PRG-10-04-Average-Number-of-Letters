//
//  main.cpp
//  CPP-PRG-10-04-Average-Number-of-Letters
//
//  Created by Keith Smith on 11/1/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify the program you wrote for Programming Challenge 3 (Word Counter), so it
//  also displays the average number of letters in each word.

#include <iostream>
#include <cstring>

using namespace std;

char *getUserInput(int *);
int *calculateCharactersTotal(char *, int *);
int *calculateWordsTotal(char *, int *);
double *calculateLettersAverage(char *, int *);
void displayResults(int *, double *);

int main()
{
    int *intSize = nullptr;
    intSize = new int;
    *intSize = 999;
    
    int *intChars = nullptr;
    int *intWords = nullptr;
    double *dblAverageLetters = nullptr;
    
    char *chrUserInput = nullptr;
    
    chrUserInput = getUserInput(intSize);
    
    intChars = calculateCharactersTotal(chrUserInput, intSize);
    
    intWords = calculateWordsTotal(chrUserInput, intChars);
    
    dblAverageLetters = calculateLettersAverage(chrUserInput, intChars);
    
    displayResults(intWords, dblAverageLetters);
    
    return 0;
}

char *getUserInput(int *intSize)
{
    char *chrTemp = nullptr;
    chrTemp = new char[*intSize];
    
    cout << "Please enter a sentence:\n";
    cin.getline(chrTemp, *intSize);
    
    return chrTemp;
}

int *calculateCharactersTotal(char *chrChars, int *intSize)
{
    int *intCharacters = nullptr;
    intCharacters = new int;
    *intCharacters = 0;
    
    for (int i = 0 ; i < *intSize ; i++)
    {
        *intCharacters += 1;
        
        if (chrChars[i] == '\0')
        {
            break;
        }
    }
    
    return intCharacters;
}

int *calculateWordsTotal(char *chrChars, int *intChars)
{
    int *intCounter = nullptr;
    intCounter = new int;
    *intCounter = 0;
    
    int *intAvgCounter = nullptr;
    intAvgCounter = new int;
    *intAvgCounter = 0;
    
    double *dblAverageLetters = nullptr;
    dblAverageLetters = new double;
    
    for (int i = 0 ; i < *intChars ; i++)
    {
        *intAvgCounter += 1;
        
        if (chrChars[i] == ' ' || chrChars[i] == '\0')
        {
            *intAvgCounter -= 1;
            *intCounter += 1;
        }
    }
    
    return intCounter;
}

double *calculateLettersAverage(char *chrChars, int *intChars)
{
    int *intCounter = nullptr;
    intCounter = new int;
    *intCounter = 0;
    
    int *intAvgCounter = nullptr;
    intAvgCounter = new int;
    *intAvgCounter = 0;
    
    double *dblAverageLetters = nullptr;
    dblAverageLetters = new double;
    
    for (int i = 0 ; i < *intChars ; i++)
    {
        *intAvgCounter += 1;
        
        if (chrChars[i] == ' ' || chrChars[i] == '\0')
        {
            *intAvgCounter -= 1;
            *intCounter += 1;
        }
    }
    
    *dblAverageLetters = static_cast<double>(*intAvgCounter)
    / static_cast<double>(*intCounter);
    
    return dblAverageLetters;
}

void displayResults(int *intResult, double *dblAvgLetters)
{
    cout << "There are " << *intResult << " words in that string." << endl;
    cout << "and the average number of letters per word: " << *dblAvgLetters << endl;
}

