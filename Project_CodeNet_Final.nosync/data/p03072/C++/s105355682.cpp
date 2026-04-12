#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,h[21],maxx=-1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)if(h[i]>=maxx)ans++,maxx=h[i];
	cout<<ans<<endl; 
}