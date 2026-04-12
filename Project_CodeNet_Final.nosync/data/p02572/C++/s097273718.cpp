#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    REP(i, 0, N) cin >> A[i];

    vector<ll> acc(N);
    acc[N - 1] = A[N - 1] % MOD;
    for (int i = N - 2; i >= 0; i--) {
        acc[i] = acc[i + 1] + A[i];
        acc[i] %= MOD;
    }

    ll ans = 0;
    REP(i, 0, N - 1) {
        ans += (A[i] * acc[i + 1]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}