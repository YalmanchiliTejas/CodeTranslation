#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


// maxn = no of digits in [ number s ] 
// maxk = max modulo asked
//    k = modulo
const int maxn = 10000,maxk = 1000 , MOD = 1e9 + 7;
int dp[maxn][2][maxk];
string s;
int K,n;

int solve(int i,int f,int k)
{
	if( i==n )return k == 0;
	if( dp[i][f][k]!=-1 )return dp[i][f][k];
	dp[i][f][k]=0;
	if( f )
	{
		for(int j=0;j<s[i]-'0';j++)
		{
			dp[i][f][k]+=solve(i+1,0,(k+j)%K);
			dp[i][f][k]%=MOD;
		}
		dp[i][f][k]+=solve(i+1,1,(k+s[i]-'0')%K);
	}
	else
	{
		for(int j=0;j<10;j++)
		{
			dp[i][f][k]+=solve(i+1,0,(k+j)%K);
			dp[i][f][k]%=MOD;
		}
	}
	return dp[i][f][k];
		
}

int32_t main()
{
	IOS
	memset(dp,-1,sizeof(dp));
	cin >> s >> K;
	n = s.length();
	
	cout << ( solve( 0 , 1 , 0 ) -1 + MOD )%MOD << endl;
	
	
	
}
