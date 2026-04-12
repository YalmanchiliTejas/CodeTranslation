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
    int N; cin >> N;
    int a[51];
    rep(i, N) cin >> a[i];
    int ans = 0;
    while(true) {
        int idx = 0;
        rep(i, N) {
            if(a[idx] < a[i]) {
                idx = i;
            }
        }
        if (a[idx] < N) break;
        int cnt = a[idx] / N;
        a[idx] -= N * cnt + cnt;
        rep(i, N) {
            a[i] += cnt;
        }
        // rep(i, N) cout << a[i] <<  " ";
        // cout << endl;
        ans += cnt;
    }
    cout << ans << endl;


    return 0;
}
