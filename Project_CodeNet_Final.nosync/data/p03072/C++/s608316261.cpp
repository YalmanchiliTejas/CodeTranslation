#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,h,ans=0;
	cin>>n;
	int f[n];
	for(int i=0;i<n;i++) cin>>f[i];
	h=f[0];
	for(int i=0;i<n;i++)
	if(h<=f[i]) ans++,h=f[i];
	cout<<ans<<endl;
}