#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010,mod=1e9+7;
int n,ans=1,x,y,high[N];
int power(int p)
{
	int ans=1,v=2;
	for(;p;p>>=1,v=1ll*v*v%mod)
	 if(p&1)ans=1ll*ans*v%mod;
	return ans;
}
void slove(int l,int r,int h,int &a,int &b)
{
	int minf=0x7fffffff,cnt=0;
	for(int i=l;i<=r;i++)
	 if(high[i]<minf)minf=high[i],cnt=1;
	 else if(high[i]==minf)cnt++;
	if(cnt==r-l+1)
	{
		a=power(r-l+1)-2;if(a<0)a+=mod;
		b=power(minf-h);
		return;
	}
	int x,y,last=0,v1=1,v2=1;
	for(int i=l;i<=r+1;i++)
	{
		if(!last&&high[i]>minf)last=i;
		else if(last&&(high[i]<=minf||i==r+1))
		{
			slove(last,i-1,minf,x,y);
			v1=1ll*v1*(x+y*2%mod)%mod;
			v2=1ll*v2*y%mod;last=0;
		}
	}
	a=1ll*v1*power(cnt)%mod;
	a=(a-v2*2)%mod;if(a<0)a+=mod;
	b=1ll*v2*power(minf-h)%mod;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 scanf("%d",&high[i]);
	for(int i=1;i<=n;i++)
	 if(high[i]>high[i-1]&&high[i]>high[i+1])
	 {
	    ans=1ll*ans*power(high[i]-max(high[i-1],high[i+1]))%mod;
	    high[i]=max(high[i-1],high[i+1]);
	 }
	slove(1,n,0,x,y);
	ans=1ll*ans*(x+y)%mod;
	printf("%d\n",ans);
	return 0;
}