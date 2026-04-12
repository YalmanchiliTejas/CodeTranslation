#include <iostream>
#include <string>

using namespace std;

int main()
{
	int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < 5; i++)
	{
		if (s[i] == 'A' && s[i + 1] == 'C')
		{
			ans = 1;
		}
	}
	if (ans == 1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}