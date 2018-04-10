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

string LetterCapitalize(string str)
{
	if (isalpha(str[0]))
		str[0] = toupper(str[0]);

	for (int i = 1; i < str.length(); i++)
	{
		if (isalpha(str[i]) && str[i - 1] == ' ')
			str[i] = toupper(str[i]);
	}

	// code goes here   
	return str;

}

string ClosestEnemyII(string matrix[], int rows)
{
	int playerRow, playerColumn;
	int columns = matrix[0].length();

	//Assuming there is always a one
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] == '1')
			{
				playerRow = i;
				playerColumn = j;
			}
		}
	}

	int minimumDistance = 9999;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] == '2')
			{
				int rowDifference = abs(i - playerRow);
				if ((columns - rowDifference) < rowDifference)
					rowDifference = columns - rowDifference;

				int columnDifference = abs(j - playerColumn);
				if ((rows - columnDifference) < columnDifference)
					columnDifference = rows - columnDifference;

				int enemyDistance = rowDifference + columnDifference;
				if (minimumDistance > enemyDistance)
					minimumDistance = enemyDistance;
			}
		}
	}
	return to_string(minimumDistance);
}