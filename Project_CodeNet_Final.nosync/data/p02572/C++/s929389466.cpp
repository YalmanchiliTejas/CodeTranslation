#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int maxn = 2e5 + 5;
typedef long long ll;
typedef uint64_t HT;
const int mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = (1LL * pre[i - 1] + a[i]) % mod;
    }
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = (1LL * ans + 1LL * pre[i - 1] * a[i]) % mod;
    }
    cout << ans << "\n";
    return 0;
}