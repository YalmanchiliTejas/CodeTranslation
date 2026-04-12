#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define pb push_back
#define fr first
#define sc second
#define endl '\n'

const int mxn = 1e6 + 5;
const ll MOD =  1e9 + 7;
ll arr[mxn];
ll pre[mxn];
int n, m, k, q;
string s, t;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + arr[i]) % MOD;
    ll ans = 0;
    for (int i = 1; i <= n; i++) (ans += arr[i] * pre[i - 1]) %= MOD;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
