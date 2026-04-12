#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll  long long
#define PR  pair<int, int>

const int N = 3e5 + 10;
const int MOD = 1e9 + 7;
const long long INF = 5e18;
const double PI = 2 * acos(0.0);
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= MOD;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long tmp = (sum[n] - sum[i] + MOD) % MOD;
        tmp *= a[i];
        tmp %= MOD;
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
