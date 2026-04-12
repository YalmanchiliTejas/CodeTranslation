#include <iostream>
using namespace std;

string S;

int main()
{
	cin >> S;

	string ANS = "Yes";

	if (S == "AAA" || S == "BBB")
	{
		ANS = "No";
	}

	cout << ANS;

	return 0;
}