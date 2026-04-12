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
string S[8];
int H, W;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> H >> W;
    
    rep(i, H) cin >> S[i];
    bool ok = true;
    rep(i, H - 1) {
        rep(j, W - 1) {
            if (S[i][j] == '#' && S[i + 1][j] == '#' && S[i][j + 1] == '#') ok = false;
            if (S[i + 1][j + 1] == '#' && S[i][j + 1] == '#' && S[i + 1][j] == '#') ok = false;
        }
    }
    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;


    return 0;
}
