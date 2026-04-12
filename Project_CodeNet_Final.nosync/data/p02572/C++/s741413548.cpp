#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll sum = 0;
    rep(i, N) sum += A[i];
    ll ans = 0;
    rep(i, N) { ans += (((sum - A[i]) % (mod * 2)) * A[i]) % (mod * 2); }
    cout << ans / 2 % mod << endl;
}