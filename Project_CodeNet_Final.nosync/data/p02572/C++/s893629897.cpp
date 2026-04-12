#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> b(n+1, 0);  // 累積和テーブル
    rep(i, n) {
        cin >> a[i];
        b[i+1] = b[i] + a[i];
    }

    ll ans = 0;

    rep(i, n) {
        ll sum = (b[n] - b[i+1]) % mod;
        ans += a[i] * sum;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}