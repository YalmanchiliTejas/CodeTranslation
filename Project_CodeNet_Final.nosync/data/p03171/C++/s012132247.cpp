#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
 
const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

ll n;
ll a[3000];
ll dp[3000][3000];

int main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,n) {
        rep(j,n-i) {
            if (i == 0) {
                if (n%2) dp[j][j+i] = a[j];
                else dp[j][j+i] = -a[j];
            } else {
                if (n%2 != i%2) dp[j][j+i] = max(dp[j][j+i-1]+a[j+i],dp[j+1][j+i]+a[j]);
                else dp[j][j+i] = min(dp[j][j+i-1]-a[j+i],dp[j+1][j+i]-a[j]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

