#pragma GCC optimize("O3")

#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/rope"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); ++i)
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define f first
#define s second

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) 
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const 
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int n;
vector<ll> a;
vector<vector<vector<ll>>> dp;
ll f(int x, int y, int t)
{
    if(x > y) return 0;
    if(dp[t][x][y] != -1) return dp[t][x][y];
    if(t)
    {
        dp[t][x][y] = max(f(x + 1, y, 0) + a[x], f(x, y - 1, 0) + a[y]);
    }
    else
    {
        dp[t][x][y] = min(f(x + 1, y, 1) - a[x], f(x, y - 1, 1) - a[y]);
    }
    return dp[t][x][y];
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.assign(n, 0);
    F0R(i, n) cin >> a[i];
    dp.assign(2, vector<vector<ll>>(n, vector<ll> (n, -1)));
    f(0, n - 1, 1);
    cout << dp[1][0][n - 1];
    return 0;
}