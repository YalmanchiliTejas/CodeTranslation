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

int G[10][10];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s][t] = true;
        G[t][s] = true;
    }  
    int ans = 0;
    int order[8];
    rep(i, N) order[i] = i;
    do {
        bool ok = true;
        rep(i, N - 1) {
            if (!G[order[i]][order[i + 1]]) ok = false;
        }
        ans += ok;
    }while(next_permutation(order + 1, order + N));
    cout << ans << endl;

    return 0;
}
