#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define LOCAL 1

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(...) cout<<#__VA_ARGS__ ": ["; for(auto e: __VA_ARGS__){cout<<e<<", ";} cout<<"]\n"
#define dbg1(...) cout<<#__VA_ARGS__ " "<< __VA_ARGS__ 
#else
#define dbg(...) 1;
#define dbg1(...) 1;
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
constexpr ll R=2e5+69, INF=2e9+6969, mod = 1e9+7;

ll ans,n,t[R],sum;

int main()
{
	scanf("%lld", &n);
	for(int i=0;i<n;++i)
	{
		scanf("%lld", &t[i]);
		sum += t[i];
		sum %= mod;
	}
	for(int i=0;i<n;++i)
	{
		sum -= t[i];
		sum %= mod;
		sum += mod;
		sum %= mod;
		ans += (t[i]*sum)%mod;
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
