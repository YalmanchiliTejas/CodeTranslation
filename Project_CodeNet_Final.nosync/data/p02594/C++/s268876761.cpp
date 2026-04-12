//const int N=1e5;
#define INF 1e9
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void sol() {
	int x; cin >> x;
	bool ok = false;
	if (x >= 30)
		ok = true;
	if (ok)
		cout << "Yes\n";
	else
		cout << "No\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		sol();
	}

	return 0;
}