#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
vector<int> num;
int k, len;
int dp[1005][5][2];
int calc(int pos, int cnt, int edge)
{
    if (pos == len)
    {
        if (cnt == k)
            return 1;
        return 0;
    }
    else if (dp[pos][cnt][edge] != -1)
        return dp[pos][cnt][edge];
    int maxdigit = 9;
    if (edge)
        maxdigit = num[pos];
    int res = 0;
    for (int i = 0; i <= maxdigit; i++)
    {
        int newedge = (edge & (i == maxdigit));
        int newcount = (cnt + (i > 0));
        if (newcount <= k)
            res += calc(pos + 1, newcount, newedge);
    }
    return (dp[pos][cnt][edge] = res);
}
signed main()
{
    string s;
    cin >> s >> k;
    len = s.length();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < len; i++)
    {
        num.pb(s[i] - '0');
    }
    int ans = calc(0, 0, 1);
    cout << ans << endl;
    return 0;
}