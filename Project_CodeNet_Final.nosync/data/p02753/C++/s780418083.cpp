#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 4;

int main()
{
	char s[MAX_N];
	int cA = 0, cB = 0;
	
	for (int i = 0; i < 3; i++)
	{
		cin >> s[i];
		if (s[i] == 'A')
		{
			cA++;
		}
		else cB++;
	}
	
	if (cA == 3 || cB == 3)
	{
		cout << "No\n";
	}
	else cout << "Yes\n";
	
	return 0;
}
