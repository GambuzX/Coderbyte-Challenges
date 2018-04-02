#include "Challenges.h"
#include <iostream>
#include <string>

using namespace std;

string LongestWord(string sen)
{
	string longestWord = "";
	int beggining = -1, end = -1;
	for (int i = 0; i < sen.length(); i++)
	{
		if (isalnum(sen[i]))
		{
			if (beggining == -1)
			{
				beggining = i;
				end = i;
			}
			else
				end++;
			if (i == sen.length() - 1)
			{
				string subString = sen.substr(beggining, end - beggining + 1);
				if (subString.length() > longestWord.length())
					longestWord = subString;
			}
		}
		else
		{
			if (beggining != -1)
			{
				string subString = sen.substr(beggining, end - beggining + 1);
				beggining = -1;
				end = -1;
				if (subString.length() > longestWord.length())
					longestWord = subString;
			}
		}
	}

	// code goes here
	return longestWord;
}

int FirstFactorial(int num)
{
	long int total = 1;
	int number = num;
	while (number > 1)
	{
		total = total * number;
		number--;
	}
	// code goes here   
	return total;

}

string FirstReverse(string str)
{
	string invertedString = str;

	for (int i = 0; i < str.length(); i++)
	{
		invertedString[i] = str[str.length()-i-1];
	}
	// code goes here   
	return invertedString;
}

string LetterChanges(string str)
{
	string copy = str;
	for (int i = 0; i < copy.length(); i++)
	{
		if (copy[i] == 'z')
			copy[i] = 'a';
		else
			if (isalpha(copy[i]))
				copy[i] = copy[i] + 1;
	}

	for (int i = 0; i < copy.length(); i++)
	{
		char letter = copy[i];
		if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
			copy[i] = toupper(copy[i]);
	}

	// code goes here   
	return copy;
}

int SimpleAdding(int num)
{
	int total = 0;
	while (num > 0)
	{
		total += num;
		num--;
	}

	// code goes here   
	return total;

}