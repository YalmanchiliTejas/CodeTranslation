
#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string input;
	bool isConnected = false;
	char firstChar;

	cin >> input;

	firstChar = input[0];

	for (int i = 1; i < input.length(); i++)
	{
		if (firstChar != input[i])
		{
			isConnected = true;
		}
	}

	if (isConnected)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}