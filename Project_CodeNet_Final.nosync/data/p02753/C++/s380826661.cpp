#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
typedef long double LD;

LL inf = 1000000000000;
LL mod = 1000000007;

int main()
{
	string s;
	cin >> s;

	LL x = 0, y = 0;
	for (auto e : s) {
		if (e == 'A') x++; else if (e == 'B') y++;
	}

	if (x && y) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

}