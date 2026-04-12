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
    int H, W;
    cin >> H >> W;
    string S[110];
    rep(i, H) cin >> S[i];
    bool a[2][110] = {};
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') a[0][i] = true;
        }
    }
    rep(j, W) {
        rep(i, H) {
            if (S[i][j] == '#') a[1][j] = true;
        }
    }
    rep(i, H) {
        if(!a[0][i]) continue;
        rep(j, W) {
            if(!a[1][j]) continue;
            cout << S[i][j];
        }
        cout << endl;
    }

    return 0;
}
