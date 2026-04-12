#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 41;
//const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

ll num[N];
ll numP[N];

ll go(ll n, ll x) {
	if (n == 0) return 1;
	if (x == 1) return 0;
	if (x - 1 <= num[n - 1]) return go(n - 1, x - 1);
	if (x - 2 == num[n - 1]) return 1 + numP[n - 1];
	return 1 + numP[n - 1] + go(n - 1, x - 2 - num[n - 1]);
}

void solve() {
	num[0] = 1;
	numP[0] = 1;
	for (int i = 1; i < 60; i++) {
		num[i] = 2 * num[i - 1] + 3;
		numP[i] = 2 * numP[i - 1] + 1;
	}

	ll n, x;
	cin >> n >> x;
	cout << go(n, x) << "\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}
