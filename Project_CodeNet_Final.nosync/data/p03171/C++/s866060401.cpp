#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll A[n];
	for(int i=0;i<n;i++)
	cin>>A[i];
	ll ans[n][n];
	for(int i=0;i<n;i++)
	{
		if(n%2==0)
		ans[i][i]=-A[i];
		else ans[i][i]=A[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if((n-i+j-1)%2==0)
			{
				ans[j][i]=max(ans[j+1][i]+A[j], ans[j][i-1]+A[i]);
			}
			else{
				ans[j][i]=min(ans[j+1][i]-A[j], ans[j][i-1]-A[i]);
			}
		}
	}
	cout<<ans[0][n-1];
	return 0;
}
