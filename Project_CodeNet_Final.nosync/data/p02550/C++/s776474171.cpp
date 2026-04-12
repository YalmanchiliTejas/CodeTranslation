#include<bits/stdc++.h>
#define mod 998244353
#define maxn 200005
using namespace std;
long long n,x,m,tt=99999999999ll;
int vis[maxn];
long long arr[maxn];
int main()
{
	long long sum=0;
	cin>>n>>x>>m;
	for (int i=1;i<=n;i++)
	{
		if (vis[x]!=0)
		{
			arr[i]=arr[i-1]+x;
			long long zhouqihe,zhouqi;
			zhouqihe=arr[i]-arr[vis[x]];
			zhouqi=i-vis[x];
			long long lef=n-i+1;
			long long tim=lef/zhouqi;
			sum+=zhouqihe*tim;
			tt=i+tim*zhouqi;
			break;
		}
		sum+=x;
		arr[i]=arr[i-1]+x;
		vis[x]=i;
		x=x*x%m;
	}
	for (tt;tt<=n;tt++)
	{
		sum+=x;
		x=x*x%m;
	}
	cout<<sum<<endl;
}