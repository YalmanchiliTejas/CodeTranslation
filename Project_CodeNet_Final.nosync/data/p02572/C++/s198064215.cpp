#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define arr(x) x, x + n
#define trav(a, x) for (auto &a : x)
#define rall(x) x.rbegin(), x.rend()
#define ll long long int
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;

void solve() {
    int n; cin >> n;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    ll ans = 0, x = 0;
    rep(i, 0, n) {
        ans = (ans + a[i] * x) % mod;
        x = (x + a[i]) % mod;
    }
    cout << ans << endl;
    return;
}

int main() {

    FIO
    solve();
    return 0;
}