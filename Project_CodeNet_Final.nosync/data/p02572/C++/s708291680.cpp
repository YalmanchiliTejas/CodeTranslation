#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

const int MOD = 1e9+7;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    vector<ll> sum(N+1,0);
    REPR(i,N-1){
        sum[i] = sum[i+1] + A[i];
        sum[i] %= MOD;
    }

    ll ans = 0;
    REP(i,N-1){
        ans += A[i] * sum[i+1];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}