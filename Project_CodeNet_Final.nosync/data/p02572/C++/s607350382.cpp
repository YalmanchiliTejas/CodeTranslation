#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

int main() {
    ll MOD = 1000000007;
    int N; cin >> N;
    vector<ll> A(N);
    ll wa = 0;
    rep(i,N) {
        cin >> A.at(i);
        wa += A[i];
        wa %= MOD;
    }
    ll res = 0;
    rep(i,N-1) {
        wa -= A[i];
        wa = (wa % MOD + MOD) % MOD;
        res += A[i] * wa % MOD;
        res %= MOD;
    }
    cout << res << endl;
}
