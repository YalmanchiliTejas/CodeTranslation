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
int a[51], b[51];

bool ableEat(int level, int eat) {
    return eat >= a[level];
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, X;
    cin >> N >> X;
    a[0] = 1, a[1] = 5;
    b[0] = 1, b[1] = 3;
    rep(i, 50) {
        a[i + 1] = a[i] * 2 + 3;
        b[i + 1] = b[i] * 2 + 1;
    }
    int level = N;
    int ans = 0;

    while(X > 0) {
        while(!ableEat(level, X) && X > 0) {
            X--; level--;
        }
        //cout << level << endl;
        if (X == 0) break;
        ans += b[level];
        X -= a[level];
        if (X > 0) {
            X--; ans++;
        } else break;

    }
    cout << ans << endl;

    return 0;
}
