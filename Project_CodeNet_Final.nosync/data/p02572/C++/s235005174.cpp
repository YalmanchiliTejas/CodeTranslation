#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (ll i = 0; i < B; i++) { ans *= A - i; }
    for (ll i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    ll e=1000000007;
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll c = 0;
    ll ans = 0;
    rep(i, N) {
        cin >> A[i];
        c += A[i];
    }
    for (ll i = N - 1; 0 < i; i--) {
        c -= A[i];
        ans += A[i]%e*(c%e);
        ans %= e;
    }
    cout << ans % e << endl;
}