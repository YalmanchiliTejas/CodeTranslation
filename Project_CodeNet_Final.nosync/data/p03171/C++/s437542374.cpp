#include <bits/stdc++.h>
#define maxn 3001
using namespace std;
typedef long long LL;

int n;
int ar[maxn];
LL dp[maxn][maxn];

int main() {
	cin >> n;
	for( int i = 1 ; i <= n ; i++ )
		cin >> ar[i];
	int l = ( n % 2 == 0 ) ? 2 : 1;
	if( l == 1 )
		for( int i = 1 ; i <= n ; i++ )
			dp[i][i] = ar[i];
	else
		for( int i = 1 ; i < n ; i++ )
			dp[i][i+1] = abs( ar[i] - ar[i+1] );
	for( int len = l + 2 ; len <= n ; len += 2 )
		for( int i = 1 ; i+len-1 <= n ; i++ ) {
			int j = i+len-1;
			LL first = min( dp[i+2][j] + ar[i] - ar[i+1] , dp[i+1][j-1] + ar[i] - ar[j] );
			LL last = min( dp[i][j-2] + ar[j] - ar[j-1] , dp[i+1][j-1] + ar[j] - ar[i] );
			dp[i][j] = max( first , last );
		}
	cout << dp[1][n];
}
