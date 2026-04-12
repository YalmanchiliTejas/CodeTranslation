#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10050;
const int M=100;
const int mod=1e9+7;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int dp[N][M];
int main()
{
	string s;
	int k;
	cin>>s;
	scanf("%i",&k);
	dp[0][0]=1;
	for(int i=1;i<=s.size();i++)
		for(int j=0;j<k;j++)
			for(int d=0;d<=9;d++)
				dp[i][j]=add(dp[i][j],dp[i-1][(j-d%k+k)%k]);
	int sum=0,ans=0;
	int sz=s.size();
	for(int i=0;i<s.size();i++)
	{
		sz--;
		for(int j=0;j<s[i]-'0';j++)
		{
			ans=add(ans,dp[sz][(k-((sum+j)%k))%k]);
		}
		sum=(sum+(s[i]-'0'))%k;
	}
	if(sum==0) ans=add(ans,1);
	ans=sub(ans,1);
	printf("%i\n",ans);
	return 0;
}