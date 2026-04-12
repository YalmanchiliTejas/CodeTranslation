#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int N;
    cin >> N;
    ll mod = 1000000007;
    ll ans = 0;
    vector<int> A(N);
    vector<ll> B(N+1, 0); //累積和
    rep(i, N) {
        cin >> A[i];
        B[i+1] = B[i]+A[i];
    }

    rep(i, N) {
        ll sum = (B[N]-B[i+1])%mod;
        ans += A[i]*sum;
        ans %= mod;
    }
    cout << ans << endl;
}