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
#define MAXN 3013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
ll arr[MAXN];
ll dp[MAXN][MAXN];
bitset<MAXN> vis[MAXN];

ll solve(int l, int r)
{
	if (l > r) return 0;
	if (vis[l][r]) return dp[l][r];
	vis[l][r] = true;
	if ((l + r + N) & 1)
	{
		dp[l][r] = max(solve(l + 1, r) + arr[l], solve(l, r - 1) + arr[r]);
	}
	else
	{
		dp[l][r] = min(solve(l + 1, r) - arr[l], solve(l, r - 1) - arr[r]);
	}
	return dp[l][r];
}


int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N) cin >> arr[i];
	cout << solve(0, N - 1) << '\n';
}
