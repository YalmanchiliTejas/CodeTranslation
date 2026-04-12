#include <bits/stdc++.h>
#pragma GCC optimize 03
#pragma GCC optimize ("unroll-loops")
#define int long long
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;
const int N = 3e5 + 2e5;
const int inf = 2e9;
const int MOD = 1e9 + 7;
const int LogN = 30;

int mod(int a) {
    a %= MOD;
    return a;
}

void solve() {
    int D, T, S;
    string s, t;
    int n;
    int ans = 0, sum = 0;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        ans = mod(ans + x * sum);
        sum = mod(sum + x);
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}
