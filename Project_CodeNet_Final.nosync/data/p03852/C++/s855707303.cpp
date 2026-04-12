#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	char c;
	cin >> c;
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		cout << "vowel\n";
	else
		cout << "consonant\n";
}
