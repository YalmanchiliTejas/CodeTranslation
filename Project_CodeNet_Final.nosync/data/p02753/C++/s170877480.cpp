#include <bits/stdc++.h>
using namespace std;

const int L = 8;

void solve() {
	string a;
	cin >> a;
	int x = 0, y = 0;
	for (int i = 0; i < 3; ++i)	{
		x += a[i] == 'A';
		y += a[i] == 'B';
	}
	if (x == 1 or y == 1) cout << "Yes" << '\n';
	else cout << "No" << '\n';	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}