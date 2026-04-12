#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl '\n'
#define PI acos(-1)
typedef long long ll;
//	Table is the complete reverse of dp
//	Always think of the pattern (LCM, GCD)
//	Be careful of unsigned
//	double epsilon = FLT_EPSILON;
//	Think of a solution that gets TLE and optimize it
const int MOD = 1e9 + 7;
int n, **dp[2], d;
string k;
int main()
{
    cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> k >> d;
    n = k.size();
    dp[0] = new int *[d];
    dp[1] = new int *[d];
    for(int i = 0; i < d; i++)
    {
    	dp[0][i] = new int[n + 1];
    	dp[1][i] = new int[n + 1];
    	dp[0][i][n] = dp[1][i][n] = 0;
    }
    dp[1][0][n] = 1;
    for(int i = n - 1; i >= 0; i--)
    	for(int rem = d - 1; rem >= 0; rem--)
    	{
    		dp[0][rem][i] = dp[1][rem][i] = 0;
    		for(int j = 9; j >= 0; j--)
			{
    			dp[1][rem][i] += dp[1][(rem + j) % d][i + 1];
    			if(dp[1][rem][i] >= MOD)
    				dp[1][rem][i] -= MOD;
			}
    		for(int j = k[i] - '0'; j >= 0; j--)
			{
				dp[0][rem][i] += dp[j != k[i] - '0'][(rem + j) % d][i + 1];
				if(dp[0][rem][i] >= MOD)
					dp[0][rem][i] -= MOD;
			}
    	}
    int ans = 0;
    for(int i = 0; i < n; i++)
    	ans += k[i] - '0';
    ans = ans % d == 0;
    cout << ((ans + dp[0][0][0] - 1) % MOD + MOD) % MOD;
}
