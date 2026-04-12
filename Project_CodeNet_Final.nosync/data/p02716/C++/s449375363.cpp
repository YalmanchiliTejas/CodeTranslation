//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    vi a(n), sumf(n+1), sumb(n+1);
    rep(i, n) {
        cin >> a[i];
    }

    if(!(n&1)) {
        rep(i, n) {
            if(i&1) {
                sumb[n-1-i] = sumb[n-i];
                sumf[i+1] = sumf[i];
            }
            else {
                sumf[i+1] = sumf[i] + a[i];
                sumb[n-1-i] = sumb[n-i] + a[n-i-1];
            }
        }

        rep(i, n+1) {
            //cout << sumf[i] << ' ' << sumb[i] << endl;
        }

        ll ans = -LINF;
        rep(i, n/2+1) {
            ll now = sumf[i*2] + sumb[i*2];
            //cout << now << endl;
            ans = max(ans, now);
        }
        cout << ans << endl;
    } else {
        vvi dp(3, vi(n+2, -LINF));
        dp[0][0] = 0;
        rep(i, n){
            rep(j, 3) {
                if((i+j)&1) continue;
                dp[j][i+2] = max(dp[j][i] + a[i], dp[j][i+2]);
                if(j != 2 and i+3 != n+2) {
                    dp[j+1][i+3] = max(dp[j][i] + a[i+1], dp[j+1][i+3]);
                }
                if(j == 0 and i+2 != n) {
                    dp[2][i+4] = max(dp[0][i] + a[i+2], dp[2][i+4]);
                }
            }
        }


        cout << max({dp[0][n-1], dp[1][n], dp[2][n+1]}) << endl;
    }
}