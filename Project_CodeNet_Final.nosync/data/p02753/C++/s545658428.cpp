#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define int ll

signed main ()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int a = 0, b = 0;
	for (char c : s) {
		a += (c == 'A');
		b += (c == 'B');
	}

	if (a and b) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;

}
