#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll MOD = 1e+9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    
    ll sum = A[0];
    ll ans = 0;
    for ( int i = 1; i < N; ++i){
        ans = ( ans + sum * A[i] ) % MOD;
        sum = ( sum + A[i] ) % MOD;
    }
    cout << ans << endl;
    return 0;
}
