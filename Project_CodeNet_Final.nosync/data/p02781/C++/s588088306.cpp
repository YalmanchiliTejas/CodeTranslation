#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;
	string t="$"+s;
	int n=s.size();
	ll dp1[101][4]={0},dp2[101][4]={0};
	dp2[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		int num=t[i]-'0';
		if(num==0)
		{
			dp1[i][0]=1;
			dp2[i][0]=0;
			for(int j=1; j<=k; j++)
			{
				dp1[i][j]=dp1[i-1][j]+dp1[i-1][j-1]*9;
				dp2[i][j]=dp2[i-1][j];
			}
		}
		else
		{
			dp1[i][0]=1;
			dp2[i][0]=0;
			for(int j=1; j<=k; j++)
			{
				dp1[i][j]=dp1[i-1][j]+dp1[i-1][j-1]*9+dp2[i-1][j]+dp2[i-1][j-1]*(num-1);
				dp2[i][j]=dp2[i-1][j-1];
			}
		}
	}
	ll ans=dp1[n][k]+dp2[n][k];
	cout<<ans;
	return 0;
	
}