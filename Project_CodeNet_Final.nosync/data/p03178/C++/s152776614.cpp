#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=1e4+5;
ll dp[N][150][2],sum,ans;
int n;string s;
int main()
{
	cin>>s>>n;
	sum=s[0]-'0';
	dp[0][sum%n][1]=1;
	for(int i=0;i<s[0]-'0';i++)dp[0][i%n][0]+=1;
	for(int i=1;i<s.size();i++)//位数 
	{
		sum+=s[i]-'0';
		for(int j=0;j<n;j++)//上一次 
		{
			for(int k=0;k<10;k++)//canadd
			{
				dp[i][(j+k)%n][0]+=dp[i-1][j][0];
				dp[i][(j+k)%n][0]%=mod;
				if(k<s[i]-'0')
				{
					dp[i][(j+k)%n][0]+=dp[i-1][j][1];
					dp[i][(j+k)%n][0]%=mod;
				}
			}
		}
		dp[i][sum%n][1]=1;
	}
	cout<<(dp[s.size()-1][0][0]+dp[s.size()-1][0][1]-1+mod)%mod<<endl;
	return 0;
}