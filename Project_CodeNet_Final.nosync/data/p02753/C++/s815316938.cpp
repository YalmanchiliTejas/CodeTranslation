#include <iostream>

using namespace std;

int main()
{
	bool res = false;

	string str;
	cin >> str;

	bool existA = false;
	bool existB = false;

	for (const char c : str)
	{
		if (c == 'A')
			existA = true;
		else if (c == 'B')
			existB = true;

		if (existA && existB)
		{
			res = true;
			break;
		}
	}

	if (res)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}