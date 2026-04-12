#include <iostream>
#include <string>


using namespace std;

int main()
{
	string s;
	cin >> s;

	bool flag = true;
	for (int i = 1; i < 3; i++)
	{
		if (s[i] != s[i - 1])
		{
			flag = false;
		}
	}

	if (!flag) cout << "Yes" << endl;
	else  cout << "No" << endl;

}