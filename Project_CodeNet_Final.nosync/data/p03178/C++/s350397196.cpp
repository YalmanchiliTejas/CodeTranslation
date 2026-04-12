
/**
    And in the end, the love you take is equal to the love you make.

        I LOVE YOU LAURA.
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_DISABLE_PERFCRIT_LOCKS

#define findOrder find_by_order
#define orderKey order_of_key

#define isOn(mask, i) (mask & (1 << i))
#define turn(mask, i) (mask |= (1 << i))
#define switch(mask, i) (mask &= ~(1 << i))
#define change(mask, i) (mask ^= (1 << i))
#define lowbit(mask) (mask & (-mask))
#define turnAll(mask, n) (mask = (1 << n) - 1)
#define switchLastBit(mask) (mask & (mask - 1))
#define turnLastZero(mask) (mask | (mask + 1))
#define modulo(x, mod) ((x) & (mod - 1))
#define log2(x) (31 - __builtin_clz(x))

#define mkp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define ef emplace_front
#define ins insert
#define rsz resize
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) ((int)x.size())
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define debug(x) (cerr << x << " ")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdb;
typedef pair<int, ii> tri;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ld> vdb;
typedef vector<cd> vcd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vll> matrix;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_tree;

const ll mod = 1e9+7;
const int maxn = 1e5+2;
const int pi = 2 * acos(0.0);
const db eps = 1e-9;

int n, d;
string s;
ll dp[maxn][105][2];

ll solve_dp (int pos, int m, int small){
    if (pos == n) return (m == 0);

    ll &ans = dp[pos][m][small];
    if (ans != -1) return ans;

    int lim = 9;
    if (small) lim = s[pos] - '0';

    ans = 0;
    for (int i = 0; i <= lim; i++){
        int next = (i < lim) ? 0 : small;
        ans = (ans + solve_dp(pos + 1, (m + i) % d, next)) % mod;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> s >> d;

    n = sz(s);

    cout << (solve_dp(0, 0, 1) - 1 + mod) % mod << "\n";

    return 0;
}
