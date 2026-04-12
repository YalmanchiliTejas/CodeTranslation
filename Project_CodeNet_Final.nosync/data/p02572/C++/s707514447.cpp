#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll mod = 1e9 + 7;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
    }
    vector<ll> T(N+1);
    rep(i, N){
        T[i+1] = T[i] + A[i];
    }

    ll ans = 0;
    for (int i = 0; i < N-1; i++){
        ll total = T[N] - T[i+1];
        total %= mod;
        total *= A[i];
        total %= mod;
        ans += total;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}