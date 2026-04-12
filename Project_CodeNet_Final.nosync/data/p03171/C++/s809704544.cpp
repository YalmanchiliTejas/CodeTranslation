//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 3e3 + 5;
const double eps = 1e-9;
int c[MAXN], vis[MAXN][MAXN][2];
ll dp[MAXN][MAXN][2];

void solve(int a, int b, int x) {
    if (vis[a][b][x]) return;
    if (a == b) {
        if (x)
            dp[a][b][x] = -c[a];
        else
            dp[a][b][x] = c[a];
        vis[a][b][x] = 1;
        return;
    }
    if (a < b) {
        solve(a, b - 1, x ^ 1);
        solve(a + 1, b, x ^ 1);
        if (x)
            dp[a][b][x] = min(dp[a][b - 1][x ^ 1] - c[b], dp[a + 1][b][x ^ 1] - c[a]);
        else
            dp[a][b][x] = max(dp[a][b - 1][x ^ 1] + c[b], dp[a + 1][b][x ^ 1] + c[a]);
    }
    vis[a][b][x] = 1;
}

int main()
{
    int n;
    ni(n);
    nai(c, n);
    solve(0, n - 1, 0);
    prl(dp[0][n - 1][0]);
    return 0;
}
