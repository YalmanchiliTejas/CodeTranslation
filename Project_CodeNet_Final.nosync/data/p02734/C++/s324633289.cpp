#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 3005, mod = 998244353;
int n, s, a[MX];
ll mem[MX][MX];

ll dp (int i, int j) {
	if (j < 0) return 0;
	if (j == 0) return n - i + 1;
	if (i == n) return 0;

	ll &res = mem[i][j];
	if (res != -1) return res;
	res = 0;

	if (j == s) res = (i + 1) * dp(i + 1, j - a[i]);
	else res = dp(i + 1, j - a[i]);
	res += dp(i + 1, j);

	res %= mod;
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	forn (i, n) cin >> a[i];

	memset(mem, -1, sizeof(mem));
	cout << dp(0, s) << endl;

	return 0;
}