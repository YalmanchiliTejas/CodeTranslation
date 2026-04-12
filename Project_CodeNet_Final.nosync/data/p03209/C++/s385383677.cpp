/*
Look at the star
Look at the shine for U
*/
#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define sl(x) scanf("%lld",&x)
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
ll inv(ll b){if(b==1)return 1; return (mod-mod/b)*inv(mod%b)%mod;}
ll fpow(ll n,ll k){ll r=1;for(;k;k>>=1){if(k&1)r=r*n%mod;n=n*n%mod;}return r;}
ll s[N],sum[N];

ll dfs(ll n,ll k)
{
	if(n == 0) return k;
    if(k <= 1) return 0;
    if(k <= 1+s[n-1]) return dfs(n-1,k-1);
    return sum[n-1]+1+dfs(n-1,min(k-s[n-1]-2,s[n-1]));
}

int main()
{
	ll n,i,k;
	while(~sl(n))
	{
		sl(k);
		if(n == 0)
		{
			puts("1");
			continue;
		}
		s[0] = sum[0] = 1;
		for(i = 1;i <= 50;i++)
			sum[i] = 2*sum[i-1]+1;
		for(i = 1;i <= 51;i++)
			s[i] = s[i-1]*2+3;
		ll ans = dfs(n,k);
		printf("%lld\n",ans);
	}
	return 0;
}
