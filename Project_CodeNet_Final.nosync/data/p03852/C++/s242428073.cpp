#include <iostream>

using namespace std;

int main()
{
	char input;
	cin >> input;
	
	if(input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u')
	{
		cout << "vowel" << endl;
	}
	else
	{
		cout << "consonant" << endl;
	}
}
