#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll MOD = 1e9 + 7;
ll dp[10010][2][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	ll m; cin >> m;
	
	vvl dp(2,vl(m));
	dp[0][0] = 1;

	FOR(i,0,sz(s)) {
		vvl ndp(2,vl(m));
		FOR(lt,0,2) FOR(j,0,m) {
			FOR(d,0,10) {
				if (!lt && d > s[i]-'0') continue;
				ll nlt = lt || (d < s[i]-'0');
				ll nj = (j + d) % m;
				ndp[nlt][nj] = (ndp[nlt][nj] + dp[lt][j]) % MOD;
			}
		}
		dp = ndp;
	}
	
	ll res = (dp[0][0] + dp[1][0] + MOD-1) % MOD;
	cout << res << endl;
}

