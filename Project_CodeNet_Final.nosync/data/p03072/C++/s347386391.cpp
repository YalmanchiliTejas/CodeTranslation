#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[21];
	int ans=0,t;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=1;j<i;j++)
		{
			if(a[i]<a[j]) t++;
		}
		if(t==0) ans++;
	}
	cout<<ans;
	return 0;
}