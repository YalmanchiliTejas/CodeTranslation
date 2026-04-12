#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

ll pw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll sum = 0, ans = 0;
	for(int i=1; i<=n; ++i)
	{
		ans = (ans + sum * a[i]) %mod;
		sum = (sum + a[i]) %mod;
	}
	printf("%lld\n",ans);
	return 0;
}