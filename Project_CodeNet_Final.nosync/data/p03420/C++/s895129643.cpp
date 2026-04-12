#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K; cin >> N >> K;
    ll ans = 0;
    REP(i, K + 1, N) {
        ans += min(N, (N / i) * (i - K) + max(0LL, (N % i + 1) - K));
        //cout << i << " " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
