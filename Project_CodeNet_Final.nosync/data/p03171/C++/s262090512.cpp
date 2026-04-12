#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
const int N = 3000;
int n, k, a[N];
ll dp[N][N][2];

ll cal(int i, int j, bool p){
	if( i > j )
		return 0;
	if( dp[i][j][p] != -1 )
		return dp[i][j][p];
	if( p == 0 )
		return dp[i][j][p] = max( cal(i+1, j, !p) + a[i], cal(i, j-1, !p) + a[j] );
	else
		return dp[i][j][p] = min( cal(i+1, j, !p) - a[i], cal(i, j-1, !p) - a[j] );
}

int main()
{
	cin >> n;
	f(i, 0, n)
		cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << cal(0, n-1, 0);
}