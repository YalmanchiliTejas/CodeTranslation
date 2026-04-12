#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = a; i < (b); ++i)

int main() {

    ll N;
    cin >> N;

    ll MOD = 1e9 + 7;
    ll sum = 0;

    vl A(N);
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }

    sum %= MOD;
    ll ans = 0;
    rep(i, N-1) {
        if (A[i] > sum) sum += MOD;
        sum -= A[i];
        ans += (sum*A[i]);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
