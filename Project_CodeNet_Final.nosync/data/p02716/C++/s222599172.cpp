#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
#define INF (ll)1e16

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (n == 2) {
        cout << max(a[0], a[1]) << endl;
        return 0;
    }
    vector<ll> dp[3];
    rep(i,3) dp[i] = vector<ll>(n, -INF);
    dp[0][0] = a[0];
    dp[1][1] = a[1];
    dp[2][2] = a[2];
    rep(i,n){
        rep(k,3){
            if (i < k) continue;
            rep(j,3){
                if (k+j <= 2 && i+j+2 < n){
                    dp[k+j][i+j+2] = max(dp[k+j][i+j+2], dp[k][i] + a[i+j+2]);
                }
            }
        }
    }
    if (n % 2 == 0){
        cout << max({dp[1][n-1], dp[0][n-2]}) << endl;
    } else {
        cout << max({dp[2][n-1], dp[1][n-2], dp[0][n-3]}) << endl;
    }

    return 0;
}
