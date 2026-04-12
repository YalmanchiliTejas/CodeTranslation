#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 105, mod = 1e9+7;
int n, h[MX];
ll dp[MX][MX][2];

ll pot (ll b, ll p, int mod) {
	ll res = 1;
	b %= mod;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}

	return res;
}

ll obtRes (int i, int j, int f, int off) {
	ll &res = dp[i][j][f];
	if (res != -1) return res;

	int mn = 2e9, cn;
	for (int k = i; k <= j; k++)
		if (h[k] < mn) {
			mn = h[k];
			cn = 1;
		} else if (h[k] == mn)
			cn++;

	if (f) {
		ll x = pot(2, cn, mod);
		ll y = pot(2, mn - off, mod) - 2;
		int ant = -1;

		for (int k = i; k <= j; k++) {
			if (h[k] > mn) {
				if (ant == -1) ant = k;
			} else {
				if (ant != -1) {
					x = x * (obtRes(ant, k-1, 1, mn) + obtRes(ant, k-1, 0, mn)) % mod;
					y = y * obtRes(ant, k-1, 0, mn) % mod;
				}
				ant = -1;
			}
		}

		if (ant != -1) {
			x = x * (obtRes(ant, j, 1, mn) + obtRes(ant, j, 0, mn)) % mod;
			y = y * obtRes(ant, j, 0, mn) % mod;
		}

		return res = (x + y) % mod;
	}

	res = pot(2, mn - off, mod);

	int ant = -1;
	for (int k = i; k <= j; k++) {
		if (h[k] > mn) {
			if (ant == -1) ant = k;
		} else {
			if (ant != -1)
				res = res * obtRes(ant, k-1, 0, mn) % mod;
			ant = -1; 
		}
	}

	if (ant != -1)
		res = res * obtRes(ant, j, 0, mn) % mod;

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	FOR(i,MX) FOR(j,MX) FOR (k,2) dp[i][j][k] = -1;

	cin >> n;
	FOR(i,n) cin >> h[i];

	cout << MOD(obtRes(0, n-1, 1, 0), mod) << endl;

	return 0;
}