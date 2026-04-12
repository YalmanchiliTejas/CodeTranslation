#include <bits/stdc++.h>
#define f                           first
#define s                           second
#define task                        "test"
#define fi			                freopen(task".inp", "r", stdin)
#define fo			                freopen(task".out", "w", stdout)
#define reset(a, b)                 memset(a, b, sizeof(a))
#define MAX(a, b)                   a = max(a, b)
#define MIN(a, b)                   a = min(a, b)
 
using namespace std;
 
typedef long long                   LL;
typedef pair<int,int>               II;
 
const LL mod = 1e9 + 7;
const LL N   = 1e5 + 5;
 
/* ------------- ------------- ------------- ------------- ------------- ------------- ------------- */
string k;
long long dp[10005][100][2];
int d;
 
long long calc(int idx, int sum, bool t)
{
    if (idx == k.size())
        return (!sum) ? 1 : 0;
    if (dp[idx][sum][t] != -1)
        return dp[idx][sum][t];
    int m = (t) ? (k[idx] - 48) : 9;
    LL res = 0;
    for (int i = 0; i <= m; i++)
    {
        bool nt = (i == (k[idx] - 48)) ? t : 0;
        res = ((LL) res + calc(idx + 1, (sum + i) % d, nt)) % mod;
    }
    return dp[idx][sum][t] = res;
}
 
void solve()
{
    cin >> k >> d;
    reset(dp, -1);
    cout << (calc(0, 0, 1) - 1 + mod) % mod;
}
 
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);
//    fi;
//    fo;
    solve();
    return 0;
}