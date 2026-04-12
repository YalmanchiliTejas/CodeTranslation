#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define maxn 200005
#define mid ((nl+nr)>>1)
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n;
ll a[maxn],b[maxn];
int main()
{
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ans+=(a[i]*b[i-1])%mod;
		ans%=mod;
		b[i]=(b[i-1]+a[i])%mod;
	}
	printf("%lld\n",ans);
}