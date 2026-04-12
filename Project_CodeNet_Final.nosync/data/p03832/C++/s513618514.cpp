#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

int comb[1111][1111];
int calc2dp[1111][1111];
int dp[1111][1111];
int n, a, b, c, d;

ll calc2(int a, int b)
{
	if (calc2dp[a][b] >= 0) return calc2dp[a][b];
	ll res = 1;
	while (a > 0)
	{
		res *= comb[a-1][b-1];
		res %= MOD;
		a -= b;
	}
	return calc2dp[a][b] = res;
}

ll calc(int rem, int p, int group)
{
	ll res = comb[rem][p * group];
	res *= calc2(p * group, p);
	return res % MOD;
}

int solve(int p, int use)
{
	if (dp[p][use] >= 0) return dp[p][use];
	if (p == a - 1)
	{
		return use == 0;
	}
	if ((a + p) * (p - a + 1) / 2 * d < use) return 0;
	ll res = 0;
	res += solve(p - 1, use);
	FOR(i, c, d + 1)
	{
		if (use < p * i) break;
		res += calc(use, p, i) * solve(p - 1, use - p * i) % MOD;
		res %= MOD;
	}
	return dp[p][use] = res;
}

ll aa[1111][1111];
void init()
{
	REP(i, 1111)
	{
		aa[i][0] = aa[0][i] = 1;
	}
	FOR(i, 1, 1111)FOR(j, 1, 1111)
	{
		aa[i][j] = (aa[i - 1][j] + aa[i][j - 1]) % MOD;
	}
	REP(i, 1111)REP(j, i + 1) comb[i][j] = aa[i - j][j];
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	init();
	MS(dp, -1);
	MS(calc2dp, -1);
	cin >> n;
	cin >> a >> b >> c >> d;
	MS(dp, -1);
	cout << solve(b, n) << endl;
	return 0;
}