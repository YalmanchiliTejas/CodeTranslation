#include <bits/stdc++.h>
#define maxk 100
#define maxn 10001
#define mod 1000000007
using namespace std;

int n,k;
string s;
int dp[maxn][maxk][2];

int f( int curr , int sum , int type ) {
	if( curr == n )
		return sum == 0;
	if( dp[curr][sum][type] != -1 )
		return dp[curr][sum][type];
	dp[curr][sum][type] = 0;
	int val = s[curr] - '0';
	if( type == 1 ) {
		for( int i = 0 ; i <= 9 ; i++ )
			dp[curr][sum][type] = ( dp[curr][sum][type] + f( curr+1 , (sum+i)%k , 1 ) ) % mod;
	}
	else {
		for( int i = 0 ; i < val ; i++ )
			dp[curr][sum][type] = ( dp[curr][sum][type] + f( curr+1 , (sum+i)%k , 1 ) ) % mod;
		dp[curr][sum][type] = ( dp[curr][sum][type] + f( curr+1 , (sum+val)%k , 0 ) ) % mod;
	}
	return dp[curr][sum][type];
}

int main() {
	cin >> s >> k;
	n = s.length();
	memset( dp , -1 , sizeof(dp) );
	cout << ( f( 0 , 0 , 0 ) - 1 + mod ) % mod;
}
