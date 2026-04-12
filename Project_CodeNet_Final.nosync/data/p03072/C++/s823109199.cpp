#include <bits/stdc++.h>
using namespace std;
int n,a[21],maxx,ans;
int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		if (a[i]>=maxx) ans++,maxx=a[i];
	}
	cout<<ans;
	return 0;
}