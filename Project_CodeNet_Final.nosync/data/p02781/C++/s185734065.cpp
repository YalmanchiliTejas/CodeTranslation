#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 2e3 + 2;
string s;
ll dp[102][4][2][2], n, k;
ll solve(int ind, int rem, bool f, bool tiny)
{
    if (ind == n) return !tiny && !rem;
    if (~dp[ind][rem][f][tiny])
        return dp[ind][rem][f][tiny];

    ll ret = 0;
    if (ind) ret += solve(ind + 1, rem, (s[ind] - '0' == 0 ? f : 1), tiny) + (!rem);
    if (rem)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (f || i < s[ind] - '0')
                ret += solve(ind + 1, rem - 1, 1, tiny);
            else if (i == s[ind] - '0')
                ret += solve(ind + 1, rem - 1, 0, tiny);
            else
                ret += solve(ind + 1, rem - 1, 0, 1);
        }
    }
    return dp[ind][rem][f][tiny] = ret;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> s >> k;
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0, k, 0 ,0);
    return 0;
}