#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	char	a, b, c;
	cin >> a >> b >> c;
	string	tmp;
	tmp += a;
	tmp += b;
	tmp += c;
	int		abc = stoi(tmp);
	cout << (abc % 4 == 0 ? "YES" : "NO") << endl;
}