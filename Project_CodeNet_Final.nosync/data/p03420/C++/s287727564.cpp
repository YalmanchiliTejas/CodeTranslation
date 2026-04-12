#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    ll ans = 0;
    for (int b=1;b<=N;b++){
        int p = N/b;
        int r = N%b;
        ans += max(0,b-K)*p + max(0,r-K+1);
    }
    if (K==0) ans -= N;

    cout << ans << "\n";
}