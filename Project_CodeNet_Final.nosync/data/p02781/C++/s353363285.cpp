#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
ll k, dp[105][4][2];
string in;
ll solve(int idx, int curK, bool allValid)
{
    if(curK > k)
        return 0;
    if(idx == in.size())
        return curK == k;
    if(dp[idx][curK][allValid] != -1)
        return dp[idx][curK][allValid];
    ll ans = 0;
    for(char c = '0'; c <= '9'; c++)
    {
        if(c < in[idx])
            ans += solve(idx + 1, curK + (c != '0'), 1);
        else
        {
            if(c == in[idx] || allValid)
                ans += solve(idx + 1, curK + (c != '0'), allValid);
        }
    }
    dp[idx][curK][allValid] = ans;
    return ans;
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> in >> k;
    cout << solve(0, 0, 0) << endl;
    return 0;
}
