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
int X[200010];
int R[200010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    
    rep(i, N) cin >> X[i];
    
    rep(i, N) R[i] = X[i];
    sort(R, R + N);
    rep(i, N) {
        if (X[i] > R[(N - 1) / 2]) cout << R[(N - 1) / 2] << endl;
        else cout << R[N/2] << endl;
    }

    return 0;
}
