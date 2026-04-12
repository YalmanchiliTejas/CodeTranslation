/* author : akshatjai258 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define int ll
#define mod int(1e9 + 7)
#define inf int(1e9)
#define endl "\n"
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define fi first
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define memf(a) memset(a, false, sizeof(a))
#define all(v) v.begin(), v.end()
#define se second
#define mp make_pair
#define pb push_back
#define w(x)  \
	int x;    \
	cin >> x; \
	while (x--)
#define ps(x, y) fixed << setprecision(y) << x
void prep()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
}
int32_t main()
{
	prep();
	ll n;
	cin>>n;
	vl v(n);
	ll sum=0;
	for(auto &x:v){ cin>>x;
	sum+=x;
	}
	vvl dp(n,vl(n));
 
	for(ll L=n-1;L>=0;L--)
	{
		for(ll R=L;R<n;R++)
		{
			if(L==R)
				dp[L][R]=v[L];
			else
			dp[L][R]=max(v[L]-dp[L+1][R],v[R]-dp[L][R-1]);
		}
	}
	cout<<(dp[0][n-1]);
	return 0;
}