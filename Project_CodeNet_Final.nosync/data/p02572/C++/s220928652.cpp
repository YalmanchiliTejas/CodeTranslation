//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define in(x, l, r) (ll)(l) <= (x) && (x) < (ll)(r)

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,0,N) cin >> A[i];

    ll m = 1000000007;
    ll sum = 0;
    rep(i,0,N) {
        sum += A[i];
    }
    sum %= m;

    ll ans = 0;
    rep(i,0,N-1) {
        sum = (sum - A[i]) % m;
        if (sum < 0) sum += m;
        ans = (ans + sum * A[i]) % m;
    }
    cout << ans << endl;
}