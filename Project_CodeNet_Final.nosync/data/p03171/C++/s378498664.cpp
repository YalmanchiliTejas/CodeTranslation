#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

long long dp_table(int l, int r, vector<vector<bool>>& flag,
                   vector<vector<long long>>& dp, const vector<long long>& a)
{
    if (l >= r) return dp[l][r] = 0;
    if (flag[l][r]) return dp[l][r];

    long long res = max(a[l] - dp_table(l + 1, r, flag, dp, a),
                        a[r - 1] - dp_table(l, r - 1, flag, dp, a));
    flag[l][r] = true;
    return dp[l][r] = res;
}
int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    vector<vector<bool>> flag(n, vector<bool>(n, false));
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    cout << dp_table(0, n, flag, dp, a) << endl;
    return 0;
}