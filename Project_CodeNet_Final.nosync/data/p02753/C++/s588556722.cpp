#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 4;

int main()
{
	string s;
	cin >> s;
	
	if (s[0] == s[1] && s[1] == s[2])
	{
		cout << "No\n";
	}
	else cout << "Yes\n";
	
	return 0;
}
