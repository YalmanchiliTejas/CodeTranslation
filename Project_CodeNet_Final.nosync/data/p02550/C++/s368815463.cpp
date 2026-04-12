#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mod,x,ans;
int a[1000005];
int a2[1000005];
signed main()
{
	cin>>n>>x>>mod;
	int pos=0,len=0,pos2=n,sum=0;
	if(n<=100000)
	{
		for(int i=1;i<=pos2;i++)
		{
			ans+=x;
			x=(x*x)%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=x;
		a[x]=i;
		a2[i]=x;
		x=(x*x)%mod;
		if(a[x])
		{
			pos=a[x];
			pos2-=i;
			len=max(1LL,i-pos+1);
			for(int k=pos;k<=i;k++) sum+=a2[k];
			break;
		}
	}
	ans+=(pos2/len)*sum;
	pos2%=len;
	for(int i=1;i<=pos2;i++)
	{
		ans+=x;
		x=(x*x)%mod;
	}
	cout<<ans;
	return 0;
}
