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
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = INF;
    rep(i, max(X, Y) + 1) {
        int cost = C * i * 2;
        cost += max(0, (X - i) * A);
        cost += max(0, (Y - i) * B);
        ans = min(ans, cost);
    }
    cout << ans << endl;

    return 0;
}
