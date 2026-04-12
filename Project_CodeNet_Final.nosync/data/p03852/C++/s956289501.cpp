#include<bits/stdc++.h>
using namespace std;
char n;

signed main()
{
	cin >> n;
	if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u')
		cout << "vowel\n";
	else
		cout << "consonant\n";
	return 0;
}
