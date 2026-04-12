
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

#define int long long
#define trace(x) cerr << #x << ": " << x << " " << endl;

inline int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
inline int sub(int a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}
inline int mul(int a, int b) { return (int)((int)a * b % MOD); }

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int dsum(int i)
{
    int ct = 0;
    while (i > 0)
    {
        ct += i % 10;
        i = i / 10;
    }
    return ct;
}

signed main()
{
    IOS
        string s;
    cin >> s;
    int d;
    cin >> d;
    // reverse(s.begin(), s.end());
    vector<vector<int>> dp(d, vector<int>(2, 0)); //1 is smaller_already 0 is not smaller yet
    dp[0][0] = 1;
    REP(i, s.size())
    {
        vector<vector<int>> ndp(d, vector<int>(2, 0));
        REP(k, d)
        ndp[(k + s[i] - '0') % d][0] = add(ndp[(k + s[i] - '0') % d][0], dp[k][0]);

        REP(l, s[i] - '0')
        REP(k, d)
        ndp[(k + l) % d][1] = add(ndp[(k + l) % d][1],dp[k][0]);
        REP(j, 10)
        REP(k, d)
        ndp[(k + j) % d][1] = add(dp[k][1], ndp[(k + j) % d][1]);
        dp = ndp;
    }

    int ans = 0;
    // cout << dp[0][1] << "\n";
    cout << sub(add(dp[0][1], dp[0][0]), 1);
}