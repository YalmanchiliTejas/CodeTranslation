#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const long long maxn=400005,mod=1e9+7;
typedef long long ll;

int n;
ll a[maxn];

ll dp[maxn][3];
ll ans=-(1ll<<62);

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int lim;
	if(n%2==1) lim=2;
	else lim=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=lim;j++)
		{
			dp[i][j]=-(1ll<<62);
			if(i==j+1) dp[i][j]=a[i];
			for(int k=0;k<=j;k++)
			{
				if(i-k-2>=1)
					dp[i][j]=max(dp[i][j],dp[i-k-2][j-k]+a[i]);
			}
			//cout<<"dp "<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			if((lim-j)+i==n)
				ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}