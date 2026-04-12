#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

void solve()
{
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
	{
		cout << "vowel" << endl;
	}
	else
	{
		cout << "consonant" << endl;
	}
}

int main()
{
	solve();
	return(0);
}