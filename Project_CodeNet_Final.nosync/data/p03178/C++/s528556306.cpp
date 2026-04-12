#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define MAXN 113

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

string s;
ll D;
ll dp[2][2][MAXN];
ll ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> D;
	dp[1][1][0] = 1;
	FOR(i, 0, SZ(s))
	{
		ll x = s[i] - '0';
		FOR(j, 0, D)
		{
			dp[i & 1][0][j] = 0;
			dp[i & 1][1][j] = 0;
		}
		FOR(j, 0, D)
		{
			FOR(k, 0, 10)
			{
				dp[i & 1][0][(j + k) % D] += dp[i & 1 ^ 1][0][j]; dp[i & 1][0][(j + k) % D] %= INF;
			}
			FOR(k, 0, x + 1)
			{
				dp[i & 1][(k == x)][(j + k) % D] += dp[i & 1 ^ 1][1][j]; dp[i & 1][(k == x)][(j + k) % D] %= INF;
			}
		}
	}
	ans = INF - 1;
	FOR(j, 0, 2)
	{
		ans += dp[SZ(s) & 1 ^ 1][j][0];
		ans %= INF;
	}
	cout << ans << '\n';
	return 0;
}
