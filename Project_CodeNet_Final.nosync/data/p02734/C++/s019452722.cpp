#include<iostream>
using namespace std;
#define mod 998244353
typedef long long ll;
ll dp[3005][3005];
ll pre[3005][3005];		
ll A[3005];
int main()
{
	int N,S;
	cin>>N>>S;
	for(int i = 1;i <= N; i++)
	cin>>A[i];
	for(int i = 1;i <= N; i++)
	{
		int a=A[i];
		pre[i][a]+=i;
		for(int j = 1; j <= S; j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
			pre[i][j]=(pre[i][j]+pre[i-1][j])%mod;
			if(j>=a)
			{
			pre[i][j]=(pre[i][j]+pre[i-1][j-a])%mod;
			}
			dp[i][j]=(dp[i][j]+pre[i][j])%mod;//*(N-i+1)
		}
	}
	cout<<dp[N][S]<<endl;
} 