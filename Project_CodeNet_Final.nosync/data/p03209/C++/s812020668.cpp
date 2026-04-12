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
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, X;
    cin >> N >> X;
    int a[51], b[51];
    a[0] = 1, a[1] = 5;
    b[0] = 1, b[1] = 3;
    rep(i, 50) {
        a[i + 1] = a[i] * 2 + 3;
        b[i + 1] = b[i] * 2 + 1;
    }
    int ok = N;
    int ans = 0;
    while(X > 0){
        while(X < a[ok] && X > 0) {
            X--; ok--;
        }
        if (X == 0) break;
        //cout << ok << endl;
        X -= a[ok];
        ans += b[ok];
        if(X == 0) break;
        X--;
        ans++;
    }
    cout << ans << endl;

    

    
    return 0;
}
