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

ll dp[3010][3010];
ll a[3010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) dp[i][i] = 0;
    
    for(int w = 1; w <= n; w++){
        for(int l = 0; l+w <= n; l++){
            int r= l + w;
            if (w%2 == n%2) dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
            else dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
        }
    }

    cout << dp[0][n] << endl;
    return 0;
}
