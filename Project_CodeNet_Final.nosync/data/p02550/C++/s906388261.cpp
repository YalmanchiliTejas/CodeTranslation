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
const int N = 1e6+10, M = 2e6+10, mod = 998244353, inf = 0x3f3f3f;
ll v[N], sum[N], mm[N]; 

int main()
{
	IOS;
	ll n, m, x, ans = 0, cnt = 0;
	cin>>n>>x>>m;
	
	while(n--)
	{
		ans += x;
		v[x]++;
		if(v[x] > 1)
			mm[++cnt] = x;
		x = x*x%m;
		if(v[x] > 2||!x)
			break;
	}
	if(!x)
	{
		cout<<ans<<nl;
		AC;
	}
	rep1(i, cnt)
		sum[i] = sum[i-1] + mm[i];
	if(cnt)
		ans += (n/cnt)*sum[cnt]+sum[n%cnt];
	cout<<ans<<nl;
	
	AC;
} 