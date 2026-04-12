#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int h[111];
int n;
int fpow2(int y)
{
	if(y==0)
		return 1;
	int ret=fpow2(y>>1);
	ret=(long long)ret*ret%mod;
	if(y&1)
		(ret<<=1)%=mod;
	return ret;
}
pair<int,int> solve(int l,int r,int nh)
{
	int mi=1010101010,cnt=0;
	for(int i=l;i<=r;i++)
		mi=min(mi,h[i]);
	for(int i=l;i<=r;i++)
		cnt+=(mi==h[i]);
	int h1=1,h2=1,st=0;
	pair<int,int> dp;
	for(int i=l;i<=r+1;i++)
		if(h[i]>mi)
		{
			if(st==0)
				st=i;
		}
		else
		{
			if(st)
			{
				dp=solve(st,i-1,mi);
				h1=(long long)dp.first*h1%mod;
				h2=((long long)dp.first*2+dp.second)*h2%mod;
				st=0;
			}
		}
	return make_pair((long long)h1*fpow2(mi-nh)%mod,((long long)h2*fpow2(cnt)+mod+mod-h1-h1)%mod);
}
int main()
{
	pair<int,int> dp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	dp=solve(1,n,0);
	printf("%d",(dp.first+dp.second)%mod);
	return 0;
}