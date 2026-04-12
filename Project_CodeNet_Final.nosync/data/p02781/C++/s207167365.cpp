#include <bits/stdc++.h>
using namespace std;
const string NAME = "z";
const int N = 111;
#define ll long long
const ll inf = 1e9 + 7;
ll t, K, dp[N][5];
string L, R;
vector<int> dg;

ll sol(int pos, int num, int dabe)
{
    if (num > K)
        return 0;
    if (pos == -1)
        return num == K;
    if (dabe && dp[pos][num] > -1)
        return dp[pos][num];
    ll cnt = 0;
    for (int i = 0; i <= max(dg[pos], dabe * 9); i++)
        cnt += sol(pos - 1, num + (i > 0), dabe | (i < dg[pos]));
    if (dabe)
        dp[pos][num] = cnt;
    //cout << pos << " " << num << " " << dp[pos][num] << "\n";
    return cnt;
}

ll cal(string u)
{
    dg.clear();
    for (auto x : u)
        dg.insert(dg.begin(), x - 48);
    return sol(dg.size() - 1, 0, 0);
}

int main()
{
    //freopen((NAME + ".inp").c_str(), "r", stdin);
    //freopen((NAME + ".out").c_str(), "w", stdout);
    ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> L >> K;
    cout << cal(L) << "\n";
    return 0;
}