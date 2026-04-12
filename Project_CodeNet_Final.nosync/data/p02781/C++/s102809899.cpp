#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define LL       long long
#define DS       pair<int, int>
#define READ(f)  freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

const int N = 105;
const int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string s;
LL k, dp[N][5][2];

int fun(int pos, int cnt, int small) {
    if (cnt > k) {
        return 0;
    }
    if (pos == s.size()) {
        return cnt == k;
    }
    LL &tmp = dp[pos][cnt][small];
    if (tmp != -1) {
        return tmp;
    }
    tmp = 0;
    int j = small ? 9 : s[pos] - '0';
    for (int i = 0; i <= j; i++) {
        tmp += fun(pos + 1, (i != 0) + cnt, i < j ? 1 : small);
    }
    return tmp;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin >> s >> k;
    memset(dp, -1, sizeof dp);
    cout << fun(0, 0, 0) << '\n';
    return 0;
}
