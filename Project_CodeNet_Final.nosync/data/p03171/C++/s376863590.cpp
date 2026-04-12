
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
const int maxn = 3005;
const int pi = 2 * acos(0.0);
const db eps = 1e-9;

ll arr[maxn], dp[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for (int left = n; left >= 1; left--){
        for (int right = left; right <= n; right++){
            if (left == right) dp[left][right] = arr[right];

            dp[left][right] = max(arr[left] - dp[left + 1][right], arr[right] - dp[left][right - 1]);
        }
    }

    cout << dp[1][n] << "\n";

    return 0;
}
