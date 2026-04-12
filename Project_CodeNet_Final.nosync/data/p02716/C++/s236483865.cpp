#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX];
ll mem[MX][5];

ll dp (int i, int k) {
	if (k < 0) return -1e18;
	if (i >= n) {
		if (k == 2) return -1e18;
		return 0;
	}

	ll &res = mem[i][k];
	if (res != -1) return res;

	return res = max(
		dp(i + 1, k - 1),
		dp(i + 2, k) + a[i]
	);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	cin >> n;
	forn (i, n) cin >> a[i];
	cout << dp(0, 1 + n % 2) << endl;

	return 0;
}