#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) 
#define X first
#define Y second 
#define nl '\n'
#define AC return 0
#define pb(a) push_back(a) 
#define mst(a,b) memset(a, b, sizeof a)
#define rep(i,n) for(int i = 0; (i)<(n); i++)
#define rep1(i,n) for(int i = 1; (i)<=(n); i++)
#define scd(a) scanf("%lld", &a)
#define scdd(a,b) scanf("%lld%lld", &a, &b)
#define scs(s) scanf("%s", s)
//#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const ll INF = (ll)0x3f3f3f3f3f3f3f, MAX = 9e18, MIN = -9e18;
const int N = 1e6+10, M = 2e6+10, mod = 1e9+7, inf = 0x3f3f3f;
ll a[N], sum[N]; 


int main()
{
	IOS;
	ll n, ans = 0;
	cin>>n;
	rep1(i, n)
	{
		cin>>a[i];
		sum[i] = (sum[i-1] + a[i])%mod;
	}
	rep1(i, n-1)
	{
		ans = (ans + (sum[n]-sum[i]+mod)%mod*a[i])%mod;
	}
	cout<<ans<<nl;
	
	AC;
} 