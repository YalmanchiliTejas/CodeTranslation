#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

typedef long long llong;
typedef pair<int, int> pii;

void solve() {

	const int n = 3;

	int res = 0;
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		res = res * 10 + val;
	}

	bool ans = res % 4 == 0;

	if (ans) cout << "YES";
	else cout << "NO";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef LOCAL
		ifstream in("in");
		cin.rdbuf(in.rdbuf());
	#endif

	solve();
}