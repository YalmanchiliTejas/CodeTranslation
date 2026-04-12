#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

ll n, x, m, ps[MAX_N], used[MAX_N];

void solve() {
    cin >> n >> x >> m;
    int idx = 1;
    ll y = x;
    while (idx <= n && !used[y]) {
        ps[idx] = ps[idx - 1] + y;
        used[y] = idx++;
        y = y * y % m;
    }
    // detect no cycle
    if (idx == n + 1) {
        cout << ps[n] << "\n";
        // cout << "No cycle\n";
        return;
    }
    // detect cycle
    // range of cycle [used[y]..idx - 1]
    ll len = idx - used[y];
    ll rng = ps[idx - 1] -  ps[used[y] - 1];
    ll last = (n - used[y] + 1) - (n - used[y] + 1) / len * len;
    ll sum_last = ps[used[y] - 1 + last] - ps[used[y] - 1];
    ll ans = ps[used[y] - 1] + (n - used[y] + 1) / len * rng + sum_last;
    cout << ans << "\n";
    // cout << used[y] << " " << idx << " " << "\n";
    // cout << ps[used[y] - 1] << " " << (n - used[y] + 1) / len * rng << " " << ps[last] << "\n";
    // cout << rng << "\n";
    // cout << ps[idx - 1] -  ps[used[y]] << " " << ps[idx - 1] -  ps[used[y] - 1] << "\n";
    // cout << y << "\n";

    // 492443256176507
    // 492443244981950
    
    // for (int i = 1; i <= 30; i++) cout << ps[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}