#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	int n;
	int mx=0;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		if(a>=mx)
		{
			ans++;
		}
		mx=max(a,mx);
	}
	cout<<ans<<endl;
}