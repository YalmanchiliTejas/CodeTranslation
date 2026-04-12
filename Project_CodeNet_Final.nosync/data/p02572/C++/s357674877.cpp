#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int MOD = 1000000007;
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    ll ans = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }

    rep(i,n) {
        sum -= a[i];
        if(sum < 0) sum += MOD;
        ans += a[i] * sum;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}