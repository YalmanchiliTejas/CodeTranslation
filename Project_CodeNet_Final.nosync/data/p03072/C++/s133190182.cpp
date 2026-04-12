#include<bits/stdc++.h>
using namespace std;
const int N=100;
int a[N];
int main()
{
	int n,maxx,ans=1;cin>>n>>maxx;
	for(int i=1,x;i<n;i++)
	  cin>>x,ans+=maxx<=x,
	  maxx=max(maxx,x);
	cout<<ans;
	return 0;
}