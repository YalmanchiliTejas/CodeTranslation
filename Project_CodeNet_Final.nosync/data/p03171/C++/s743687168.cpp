#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)3e3+5)
#define MOD ((int)1e9 + 7) 
#define ll long long
#define _ << " " <<
#define TRACE(x) cout << #x << " = " << x << endl;
#define pb push_back
#define MP make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vii vector<pi>
#define all(x) x.begin(), x.end()
#define INF (LLONG_MAX-1LL)

ll n,m,t,k;
//     L  ,   R  , turn
ll d[MAXN];
ll dp[MAXN][MAXN][2];

ll rec(ll L, ll R, bool turn)
{
	if(dp[L][R][turn])
		return dp[L][R][turn];
	if(L == R) return dp[L][R][turn] = (d[L] * (1-turn)) + (-d[L])*(turn);

	if(turn) // sira 1 de
	{
		return dp[L][R][turn] = min(
			rec(L+1,R,!turn) - d[L] ,
			rec(L,R-1,!turn) - d[R]
		);
	}
	else
	{
		return dp[L][R][turn] = max(
			rec(L+1,R,!turn) + d[L] ,
			rec(L,R-1,!turn) + d[R]
		);
	} 
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> d[i];
	ll ans = rec(0,n-1,0);
	cout << fixed << ans << endl;	
	return 0;
}
