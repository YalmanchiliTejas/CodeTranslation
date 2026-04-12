#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
const int N = 3000, M = 7 + 1e9;
int n, a[N];
ll dp[N][N][2];
int main()
{
	cin >> n;
	f(i, 0, n)
		cin >> a[i];
	f(i, 0, n)
		dp[i][i][0] = -a[i]; // of length 1
	f(i, 0, n)
		dp[i][i][1] = a[i];
	
	f(i, 2, n+1){//all continous with len i
		f(j, 0, n-i+1){
			int r = j, l = j+i-1;
			dp[r][l][0] = min(dp[r+1][l][1]-a[r], dp[r][l-1][1]-a[l]);
			dp[r][l][1] = max(dp[r+1][l][0]+a[r], dp[r][l-1][0]+a[l]);
		}
	}
	cout << dp[0][n-1][1];
 
}