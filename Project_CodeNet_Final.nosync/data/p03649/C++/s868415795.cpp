#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long int

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    sort(a, a+N);
    int ans = 0;
    while(a[N-1] >= N) {
       int cnt = a[N-1]/N;
       a[N-1] -= cnt * N;
       rep(i, N-1) a[i] += cnt;
       sort(a, a+N);
        ans += cnt;
    }
    cout << ans << endl;
    



    return 0;
}
