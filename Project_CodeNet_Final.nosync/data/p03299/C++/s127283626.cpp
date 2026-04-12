#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int h[110];
int n;
inline ll quickpow(ll base,int ind)
{
	ll ans=1;
	while(ind>0)
	{
		if(ind&1)ans=ans*base%MOD;
		ind>>=1;
		base=base*base%MOD;
	}
	return ans;
}
pair<ll,ll> solve(int l,int r)
{
	int minval=inf;
	for(int i=l;i<=r;i++)
		minval=min(minval,h[i]);
//	cout<<l<<" "<<r<<" "<<minval<<endl;
	int st=l;
	ll cross=2,all=1;
	for(int i=l;i<=r+1;i++)
		if(i>r||h[i]==minval)
		{
			if(i>st)
			{
				for(int j=st;j<i;j++)
					h[j]-=minval;
				pair<ll,ll> tmp=solve(st,i-1);
				cross=cross*tmp.first%MOD;
				all=all*(tmp.first+tmp.second)%MOD;
			}
			st=i+1;
			if(i<=r)all=all*2%MOD;
		}
	all=(all-cross+MOD)%MOD;
	cross=cross*quickpow(2,minval-1)%MOD;
	all=(all+cross)%MOD;
//	cout<<cross<<" "<<all<<endl;
	return make_pair(cross,all);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&h[i]);
	}
	printf("%lld\n",solve(0,n-1).second);
	return 0;
}