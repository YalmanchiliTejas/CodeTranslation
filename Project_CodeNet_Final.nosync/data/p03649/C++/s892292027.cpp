#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(var,n)  for(int var=0;var<(n);++var)

ll solve(ll N, vector<ll>& a) {
    ll ans = 0;
    while (true) {
        ll s = 0;
        rep(i, N) {
            s += a[i] / N;
        }
        if (s == 0) break;
        ans += s;
        rep(i, N) {
            ll q = a[i] / N;
            a[i] = a[i] - q*N + (s - q);
        }
    }
    return ans;
}

int main() {
    int N; cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    cout << solve(N,a) << endl;
    return 0;
}
