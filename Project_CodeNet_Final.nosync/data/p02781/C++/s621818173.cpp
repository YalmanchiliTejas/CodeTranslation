#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int dp[101][4][2];
string s;
int N,K;

int solve(int I,int k,int f)
{
	if( k > K )return 0;
	if( I == N)return k==K;
	int &ans = dp[I][k][f];
	if( ans!=-1 )return ans;
	ans=0;
	if(f)
	{
		for(int i=0;i<s[I]-'0';i++)
		{
			ans+=solve(I+1,k+(i!=0),0);
		}
		ans+=solve(I+1,k+(s[I]!='0'),1);
	}
	else
	{
		for(int i=0;i<10;i++)
		ans+=solve(I+1,k+(i!=0),0);
	}
	return ans;
}
int32_t main()
{
	memset(dp,-1,sizeof(dp));
	cin >> s >> K; N=s.length();
	cout << solve(0,0,1) << endl;
}
	

