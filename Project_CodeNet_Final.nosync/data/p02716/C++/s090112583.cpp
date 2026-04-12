#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll dp[200010][10];
ll a[200010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];    
    rep(i, n+1) rep(j, 3) dp[i][j] = -LINF;

    dp[1][0] = a[0];
    dp[2][1] = a[1];
    if (n > 2) dp[3][2] = a[2];

    for(int i = 0; i < n; i++){
        rep(j, 3){
            for(int d = 0; d < 3-j; d++){
                int p = i-d-1; // 何日前を見るか
                if (p > 0){
                    dp[i+1][j+d] = max(dp[i+1][j+d], dp[p][j] + a[i]);
                }
            }
        }
    }
    
    ll ans = -LINF;

    int m = 1 + n%2;
    for(int d = 0; d <= m; d++){ // 最後を空ける箇所を全てチェック
        int i = n-d;
        ans = max(ans, dp[i][m-d]);
    }
    cout << ans << endl;
    return 0;
}