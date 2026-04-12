#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const ll mod = (ll)1e9 + 7;
string str;
ll d, ans = 0;
vector<vvi> dp;

// Digit DP - Is actually NOT Easy even if thought about for enough time.

// Version 1
// inline void solve()
// {

//     for (int i = 1; i < 10; i++)
//     {
//         dp[str.size() - 1][i % d] = 1;
//     }

//     for (int i = str.size() - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < d; j++)
//         {
//             for (int k = 0; k < 10; k++)
//             {
//                 int x = (int) (str[i] - '0') ;
//                 if ((i > 0 && x > 0) || ((i == 0 || x == 0) && j <= x))
//                     dp[i][j] = (dp[i][j] + dp[i + 1][(j - k + d) % d]) % mod;
//             }
//         }
//     }
// }
// Wrong because account extra for many cases


inline ll solve(int pos, int cnt, bool tight = false)
{
    if (pos == str.size())
    {
        if (!(cnt % d))
            return 1;
        return 0;
    }

    if (dp[pos][cnt][tight] != -1)
        return dp[pos][cnt][tight];
    
    ll res = 0;
    int x = (int) (str[pos] - '0');
    int lmt;
    if (tight)
        lmt = 9;
    else
        lmt = x;
    
    for (int i = 0; i <= lmt; i++)
    {
        int new_bool = tight;
        int new_cnt = cnt % d;
        if (!tight && i < lmt)
            new_bool = true;
        new_cnt = (i + new_cnt) % d;
        res = (res + solve(pos + 1, new_cnt, new_bool)) % mod;
    }

    return dp[pos][cnt][tight] = res;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str >> d;
    dp.resize(str.size() + 1, vvi(d + 2, vi(2, -1)));
    cout << (solve(0,0) - 1 + mod) % mod << endl;
    return 0;
}