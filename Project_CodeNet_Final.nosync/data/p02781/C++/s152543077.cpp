//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define pb push_back
#define F first
#define S second
#define ins insert
#define mp make_pair
#define fo(i, n1, n, x) for(int i = n1; i <= n; i += x)
#define foo(i, n, n1, x) for(int i = n; i >= n1; i -= x)
#define bit __builtin_popcount
#define md (l + ((r - l) / 2))
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;


using ll = long long;

#define int ll


const int N = 5e3 + 11, mod = 1e9 + 7, mod2 = 998244353;
const int MAX = 1e5 + 11;
const int INF1 = 2e9 + 11;
const ll INF2 = 2e18 + 11;
const double INF3 = 1e8 + 11;
const int base = 500;
const int P = 31;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const double EPS = 1e-4;
const double PI = acos(-1.0);


template<typename T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }


typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string n;
int k, ans, dp[N][2][5];
int solve(int x, bool flag, int now) {
    if (now > k) return 0;
    int &res = dp[x][flag][now];
    if (~res) return res;
    if (x == n.size() + 1) return res = (now == k);
    res = 0;
    if (flag) {
        for (int i = 0; i < 10; ++i) res += solve(x + 1, 1, now + (i > 0));
    } else {
        for (int i = 0; i < 10; ++i) {
            int cur = n[x - 1] - '0';
            if (i < cur) {
                res += solve(x + 1, 1, now + (i > 0));
            } else {
                if (i == cur) res += solve(x + 1, 0, now + (i > 0));
                break;
            }
        }
    }
    return res;
}
main() {
    file("threesum");
    ios;
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0, 0);
    cerr << "\nTime elapsed: " << (clock() + 0.0) / CLOCKS_PER_SEC;
    return 0;
}
/**

*/
