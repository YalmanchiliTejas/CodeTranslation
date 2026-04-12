#include<bits/stdc++.h>
using namespace std;
int n,h[25];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	int hi=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		hi=max(hi,h[i]);
		if(h[i]>=hi)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
