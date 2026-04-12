#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;
string str;
ll n,d;
ll dp[10005][101][2];
int test = 0;
void print_mat(int idx)
{
	cout<<"index :"<<idx<<endl;
	cout<<"loose :"<<endl;

	for(int i=0;i<d;i++)
		cout<<i<<" : "<<dp[idx][i][0]<<endl;

	cout<<"tight :"<<endl;

	for(int i=0;i<d;i++)
		cout<<i<<" : "<<dp[idx][i][1]<<endl;

}
void foo()
{
	int val = str[n-1]-'0';


	memset(dp,0,sizeof(dp));

	for(int i=0;i<=9;i++)
	{
		dp[n-1][i%d][0]++;
	}

	for(int i=0;i<=val;i++)
	{
		dp[n-1][i%d][1]++;
	}

	for(ll idx=n-2;idx>=0;idx--)
	{
		if(test) print_mat(idx+1);

		val = str[idx]-'0';
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<d;j++)
			{
				dp[idx][(i+j)%d][0] = (dp[idx][(i+j)%d][0]+dp[idx+1][j][0])%mod;
				//if(dp[idx][(i+j)%d][0] < 0) dp[idx][(i+j)%d][0]+=mod;
				//else dp[idx][(i+j)%d][0] = dp[idx][(i+j)%d][0]%mod;
			}
		}

		for(int i=0;i<val;i++)
		{
			for(int j=0;j<d;j++)
			{
				dp[idx][(i+j)%d][1] = (dp[idx][(i+j)%d][1]+dp[idx+1][j][0])%mod;
				//if(dp[idx][(i+j)%d][1] <0) dp[idx][(i+j)%d][1]+=mod;
				//else dp[idx][(i+j)%d][1] = dp[idx][(i+j)%d][1]%mod;
			}
		}

		for(int j=0;j<d;j++)
		{
			dp[idx][(val+j)%d][1] = (dp[idx][(val+j)%d][1]+dp[idx+1][j][1])%mod;
			//if(dp[idx][(val+j)%d][1] < 0) dp[idx][(val+j)%d][1]+=mod;
			//else dp[idx][(val+j)%d][1] = dp[idx][(val+j)%d][1] % mod;
		}
	}


	ll ans = dp[0][0][1]-1;
	if(ans < 0) ans+=mod;
	cout<<ans<<endl;

}
int main()
{
	cin>>str;
	n = str.length();
	cin>>d;
	foo();
}