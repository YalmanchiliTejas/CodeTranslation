#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 200001
#define ll long long
#define int ll
#define pi pair<int, int>
#define pip pair<pair, int>
#define mp make_pair
#define f first
#define s second
#define mod 998244353
int dp[1002][5][2];
int k;
string str;
int n;
int solve(int pos, int cnt, bool tight)
{
    if (pos == n && cnt == k)
        return 1;
    else if (pos == n && cnt != k)
        return 0;
    if (dp[pos][cnt][tight] != -1)
        return dp[pos][cnt][tight];
    ll ret = 0;
    ll en = tight ? (str[pos] - '0') : 9;
    for (int i = 0; i <= en; i++)
    {
        ll cntupd = cnt + (i > 0);
        if (cntupd <= k)
        {
            ret += solve(pos + 1, cntupd, (tight & (i == en)));
        }
    }
    return (dp[pos][cnt][tight] = ret);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    n = str.length();
    cin >> k;
    memset(dp, -1, sizeof dp);
    ll ans = solve(0, 0, true);
    cout << ans << endl;
}
