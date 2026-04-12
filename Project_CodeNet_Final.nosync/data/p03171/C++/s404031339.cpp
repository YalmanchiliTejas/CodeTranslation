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
ll **dp[2], flag;
ll solve(bool turn = 0, int i = 0, int j = n - 1)
{
	if(i == j)
		return dp[turn][i][j] = (turn? -1: 1) * x[i];
	ll &ret = dp[turn][i][j];
	if(ret != flag)
		return ret;
	if(!turn)
		return ret = max(x[i] + solve(!turn, i + 1, j), x[j] + solve(!turn, i, j - 1));
	else
		return ret = min(-x[i] + solve(!turn, i + 1, j), -x[j] + solve(!turn, i, j - 1));
}
int main()
{
    cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> n;
    memset(&flag, -127, 8);
    x = new int[n];
    dp[0] = new ll *[n];
    dp[1] = new ll *[n];
    for(int i = 0; i < n; i++)
    {
    	cin >> x[i];
    	dp[0][i] = new ll[n];
    	dp[1][i] = new ll[n];
    	memset(dp[0][i], -127, n * 8);
    	memset(dp[1][i], -127, n * 8);
    }
    cout << solve();
}
