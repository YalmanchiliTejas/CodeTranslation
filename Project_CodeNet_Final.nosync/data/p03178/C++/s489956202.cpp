#include<iostream>
using namespace std;
long long dp[10005][105][2];
string k;
int n,d;
long long rec(int i,int sum,int ch){
	if(i==n&&sum==0)return 1;
	if(i==n)return 0;
	if(dp[i][sum][ch]!=-1)return dp[i][sum][ch];
	dp[i][sum][ch]=0;
	if(!ch)for(int j=0;j<=9;j++){
		dp[i][sum][ch]=(dp[i][sum][ch]+rec(i+1,(sum+j)%d,0))%(1000000007);
	}
	else for(int j=0;j<=(k[i]-'0');j++){
		dp[i][sum][ch]=(dp[i][sum][ch]+rec(i+1,(sum+j)%d,(j==k[i]-'0')?1:0))%1000000007;
	}
	return dp[i][sum][ch];
}
int main()
{
	cin>>k>>d;
	n=k.length();
	long long pre=0,ans=0;
	for(int i=0;i<n;i++)for(int j=0;j<=d;j++)dp[i][j][0]=dp[i][j][1]=-1;
	ans=(rec(0,0,1)+1000000006)%1000000007;
	cout<<ans;
}