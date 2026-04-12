/*Hatsune Miku 4ever!*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i,a,b) for(int i = (a);i < b;i ++)
#define _rep(i,a,b) for(int i = (a);i > b;i --)
#define INF 0x3f3f3f3f
#define mod 1000000007
#define lowbit(x) ((x)&(-x))
#define pb push_back
#define MIKU 39
#define Design ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug() printf("Miku Check OK!\n")
#define maxn 200039

struct pres
{
	//数组长度 
	ll n;
	ll a[maxn];
	ll s[maxn];
	void getsum()
	{
		_for(i,1,n+1)
		{
			s[i] = s[i-1]+a[i];
			s[i] %= mod;
		}
	}
	ll asksum(ll l,ll r)
	{
		if(l>r)
			return 0; 
        return (s[r] - s[l-1] + mod) % mod;
	}
} P;

int main()
{
	scanf("%d",&P.n);
	_for(i,1,P.n+1)
		scanf("%lld",&P.a[i]);
	P.getsum();
	ll ans = 0;
	_for(i,1,P.n)
	{
		ans += P.a[i]*P.asksum(i+1,P.n);
		ans %= mod;
	}
	printf("%lld",ans);
	return 0;
}