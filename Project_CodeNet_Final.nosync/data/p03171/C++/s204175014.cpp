#include <bits/stdc++.h>
//#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define ones(n) __builtin_popcount(n)
#define ONES(n) __builtin_popcountll(n)

using namespace std;
//using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<int, int> ii;
typedef pair<long long, pair<int, int>> iii;
typedef pair<ii, ii> iiii;

const double PI = acos(-1.0), EPS = 1e-6;
const int N = 3003, M = 102, mod = 1000000007, mxLog = 20;
int a[N], n;
long long memo[N][N][2];

long long solve(int i, int j, int turn) {
    if (i > j)
        return 0;
    long long &ret = memo[i][j][turn];
    if (~ret)
        return ret;
    ret = 0;
    if (turn) {
        long long x = -a[i] + solve(i + 1, j, !turn);
        long long y = -a[j] + solve(i, j - 1, !turn);
        if (x > y)
            return ret = y;
        else
            return ret = x;
    } else {
        long long x = a[i] + solve(i + 1, j, !turn);
        long long y = a[j] + solve(i, j - 1, !turn);
        if (x > y)
            return ret = x;
        else
            return ret = y;
    }
}


int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    memset(memo, -1, sizeof memo);
    cout << solve(0, n - 1, 0);

    return 0;
}