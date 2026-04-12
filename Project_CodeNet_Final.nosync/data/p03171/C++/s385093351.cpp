#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,f[3030][3030],a[3030];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(n&1)
			f[i][i]=a[i];
		else
			f[i][i]=a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(((i+1)&1)==(n&1) && i!=1)
				f[j][i+j]=max(f[j+1][j+i]+f[j][j],f[j][j+i-1]+f[j+i][j+i]);
			else if(((i+1)&1)==(n&1) && i==1)
				f[j][i+j]=max(f[j+1][j+i]-f[j][j],f[j][j+i-1]-f[j+i][j+i]);
			else
				f[j][i+j]=min(f[j+1][j+i]-f[j][j],f[j][j+i-1]-f[j+i][j+i]);
		} 
	}
	cout<<f[1][n]<<endl;
	return 0;
}