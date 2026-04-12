#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define MP make_pair
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a, b) for(int i = b - 1; i >= a; --i)
#define EB emplace_back
#define ST first
#define ND second
#define S size()
#define RS resize

using VI = vector<int>;
using VVI = vector<VI>;
using PI = pair<int, int>;
using VPI = vector<PI>;
using VVPI = vector<VPI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VB = vector<bool>;

int main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string k;
    int d, mod = 1000000007;
    cin >> k >> d;
    int s = int(k.S);
    if (s == 1)
    {   
        int wyn = 0;
        FOR(i, 1, k[0] - '0' + 1)
            if (i % d == 0)
                wyn++;
        cout << wyn;
        return 0;
    }
    vector<VVI> dp(s);
    REP(i, s)
    {
       dp[i].RS(d);
       REP(j, d)
          dp[i][j].RS(10);
    }
    FOR(i, 0, 10)
        dp[0][i % d][i] = 1;
    FOR(i, 1, s)
        REP(j, d)
            REP(l, 10)
                REP(m, 10)
                {
                    int a = j - l;
                    while (a < 0)
                        a += d;
                    dp[i][j][l] += dp[i - 1][a][m];
                    dp[i][j][l] %= mod;
                }
    int wyn = -1;
    int akt_d = 0;
    REPR(i, s)
    {   
        int x = k[s - i - 1] - '0';
        FOR(j, 0, x)
        {   
            wyn += dp[i][akt_d][j];
            wyn %= mod;
        }
        akt_d -= k[s - i - 1] - '0';
        while (akt_d < 0)
            akt_d += d;
    }
    if (akt_d == 0)
        wyn += 1;
    wyn %= mod;
    cout << wyn;
    return 0;
}
