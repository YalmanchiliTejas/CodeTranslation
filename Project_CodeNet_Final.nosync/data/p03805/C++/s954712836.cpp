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

bool exist[9][9];
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
        exist[s][t] = true;
        exist[t][s] = true;
    }
    int order[10];
    rep(i, N) order[i] = i;
    int cnt = 0;
    do{
        bool ok = true;
        rep(i, N - 1) {
            int k1 = order[i];
            int k2 = order[i + 1];
            if (!exist[k1][k2]) ok = false;
        }
        cnt += ok;
    }while(next_permutation(order + 1, order + N));
    cout << cnt << endl;

    return 0;
}
