#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl '\n'
#define PI acos(-1)
typedef long long ll;
//  Table is the complete reverse of dp
//  Always think of the pattern (LCM, GCD)
//  Be careful of unsigned
//  double epsilon = FLT_EPSILON;
//	Think of a solution that gets TLE and optimize it
int n, *x;
ll **dp[2];
int main()
{
    cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> n;
    x = new int[n];
    dp[0] = new ll *[n];
    dp[1] = new ll *[n];
    for(int i = 0; i < n; i++)
    {
    	cin >> x[i];
    	dp[0][i] = new ll[n];
    	dp[1][i] = new ll[n];
    	dp[0][i][i] = x[i];
    	dp[1][i][i] = -x[i];
    }
    for(int sz = 1; sz < n; sz++)
    	for(int i = 0; i + sz < n; i++)
    	{
			dp[0][i][i + sz] = max(x[i] + dp[1][i + 1][i + sz], x[i + sz] + dp[1][i][i + sz - 1]);
			dp[1][i][i + sz] = min(-x[i] + dp[0][i + 1][i + sz], -x[i + sz] + dp[0][i][i + sz - 1]);
    	}
    cout << dp[0][0][n - 1];
}
