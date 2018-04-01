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
