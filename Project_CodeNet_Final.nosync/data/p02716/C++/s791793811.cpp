#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

template<class T> using OS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld double
#define ull unsigned long long

const int N = 2e5 + 5;
ll n, a[N], dp[N], pre[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    pre[1] = a[1];
    for (int i = 3; i <= n; i += 2) pre[i] += pre[i - 2] + a[i];

    for (int i = 2; i <= n; i++) {
        if (i & 1) {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        } else {
            dp[i] = a[i] + dp[i - 2];
            dp[i] = max(dp[i], pre[i - 1]);
        }
    }
    cout << dp[n];

    return 0;
}