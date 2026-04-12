#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[3030][3030],n,a[3030],t;
int main()
{
	cin>>n;
	if(n%2)
		t=1;
	else
		t=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][i]=t*a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if((i+1+n)%2)
				f[j][j+i]=min(f[j+1][j+i]-a[j],f[j][j+i-1]-a[j+i]);
			else
				f[j][j+i]=max(f[j+1][j+i]+a[j],f[j][j+i-1]+a[j+i]);
		//	cout<<j<<' '<<j+i<<' '<<f[j][j+i]<<endl;
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
