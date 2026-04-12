#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=111;
const int mod=1e9+7;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%mod;
		x=(LL)x*x%mod;
		y>>=1;
	}
	return ret;
}

int n,h[maxn];

pii solve(int l,int r,int v)
{
	if(l==r)return mp(qpow(2,h[l]-v),0);
	
	int mn=*min_element(h+l,h+r+1);
	vector<int> pos;pos.pb(l-1);for(int i=l;i<=r;i++)if(h[i]==mn)pos.pb(i);pos.pb(r+1);
	vector<pii> ansv;
	for(int i=1;i<(int)pos.size();i++)if(pos[i]>pos[i-1]+1)ansv.pb(solve(pos[i-1]+1,pos[i]-1,mn));
	
	int v1=2,v2=qpow(2,(int)pos.size()-2);
	for(int i=0;i<(int)ansv.size();i++)
	{
		v1=(LL)v1*ansv[i].ff%mod;
		v2=(LL)v2*(ansv[i].ff*2ll+ansv[i].ss)%mod;
	}
	v2-=v1;if(v2<0)v2+=mod;
	v1=(LL)v1*qpow(2,mn-v-1)%mod;
	return mp(v1,v2);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",h+i);
	
	pii ans=solve(1,n,0);
	printf("%d\n",(ans.ff+ans.ss)%mod);
	return 0;
}