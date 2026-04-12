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
int N, X; 
int a[51], b[51];

int f(int N, int X) {
    if (X == 0) return 0;
    if (N == 0) return 1;
    int ret = 0;
    X--;
    if (X >= a[N - 1]) {
        ret += b[N - 1];
        X -= a[N - 1];
        if (X <= 0) return ret;
        X--;
        ret++;
        if (X >= a[N - 1]) {
            ret += b[N - 1];
            X -= a[N - 1];
            X--;
            return ret;
        } else {
            return f(N - 1, X) + ret;
        }
    } else {
        return f(N - 1, X);
    }
    

    
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X;
    
    a[0] = 1;
    b[0] = 1;
    rep(i, N) a[i + 1] = a[i] * 2 + 3;
    rep(i, N) b[i + 1] = b[i] * 2 + 1;
    cout << f(N, X) << endl;

    return 0;
}
