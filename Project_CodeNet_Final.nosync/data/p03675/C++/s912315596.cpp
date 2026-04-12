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
    int N; cin >> N;
    int a[200010];
    rep(i, N) cin >> a[i];
    deque<int> dq;
    rep(i, N) {
        if (N % 2 != i % 2) dq.push_front(a[i]);
        else dq.push_back(a[i]);
    }
    rep(i, N) {
        if (i != 0) cout << " ";
        cout << dq[i];
    }
    cout << endl;

    return 0;
}
