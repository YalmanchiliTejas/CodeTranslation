#include<cstdio>
#include<algorithm>
#include<iostream>
typedef long long LL;
using namespace std;
int main()
{
	int n,ans,h[200];
	cin>>n;ans=n;
	for(int i=1;i<=n;i++)
	cin>>h[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)
	{
		if(h[j]>h[i])
		{
			ans--;break;
		}
	}
	cout<<ans;
}
