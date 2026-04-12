#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define MOD 1000000007ll
using namespace __gnu_pbds;
using namespace std;

int n,a[200010];

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return (res*res)%MOD;
	else return (((res*res)%MOD)*x)%MOD; 
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int sum=0ll;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	sum%=MOD;
	sum=(sum*sum)%MOD;
	for(int i=1;i<=n;i++) sum-=(a[i]*a[i])%MOD;
	sum%=MOD;
	if(sum<0ll) sum+=MOD;
	sum=(sum*my_pow(2ll,MOD-2ll))%MOD;
	cout<<sum<<endl;
	return 0;
}