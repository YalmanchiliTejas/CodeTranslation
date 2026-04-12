#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stack>

#define int long long
#define all(x) x.begin(), x.end()
#define forn(i, x) for(int i = i; i < x; ++i)

using namespace std;

int INF = 1e16 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& a : a) cin >> a;
    int s = 0;
    int mod = 1e9 + 7;
    for (auto a : a) {
        s += a;
        s %= mod;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        s -= a[i];
        if (s < 0) s += mod;
        ans += a[i] * s;
        ans %= mod;
    }
    cout << ans;
}

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cout << setprecision(10) << fixed;

    solve();

    return 0;
}