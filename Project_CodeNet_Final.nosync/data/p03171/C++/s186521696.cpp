#include "bits/stdc++.h"
using namespace std;

#define show(x) cerr << #x << " = " << x << endl ;
#define input_from_file freopen("input.txt","r",stdin)
#define output_to_file freopen("output.txt" , "w",stdout)
#define fastio ios_base::sync_with_stdio(0)
#define endl '\n'

const int N = 3e3+5;
long long dp[N][N][2] , in[N] , pre[N];
int main()
{
	#ifdef LOCAL
        input_from_file;
        output_to_file;
    #endif
	fastio;cin.tie(0);cout.tie(0);
	int n ; cin >> n ;
	for(int i = 1 ; i <= n ; ++i)
		cin >> in[i] , pre[i] = pre[i-1] + in[i]; 
	for(int dif = 0 ; dif < n ; ++dif)
	{
		for(int i = 1 ; i <= n - dif ; ++i)
		{
			dp[i][i+dif][1] = max(dp[i+1][i+dif][2]+in[i] , dp[i][i+dif-1][2] + in[i+dif]);
			dp[i][i+dif][2] = pre[i+dif] - pre[i-1] - dp[i][i+dif][1];
			// cerr << i << " "<< i+dif << " "<<dp[i][i+dif][1] << " "<< dp[i][i+dif][2] << endl;
		}
	}

	cout << dp[1][n][1] - (pre[n] - dp[1][n][1]);

	return 0;
}