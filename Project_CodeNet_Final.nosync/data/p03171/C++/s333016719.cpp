//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum=0LL;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    int x = 0;//ラストが二郎の手番なら0
    if(n&1) {
        x = 1;
    }
    vector<vector<ll> > dp(n+1, vector<ll>(n+1, 0LL));
    rep(i, n+1) {
        rep(j, i+1) {
            if(!((i-j)%2) && i != j && x){
                dp[i][j] = INT64_MAX;
                dp[j][i] = INT64_MAX;
            }
            if(((i-j)%2) && !x) {
                dp[i][j] = INT64_MAX;
                dp[j][i] = INT64_MAX;
            }
        }
    }

    rep(i, n) {
        rep(j, n+1-i) {
            if(x) {
                if(j>0) {
                    dp[j-1][j+i] = max(dp[j-1][j+i], dp[j][j+i]+a[j-1]);
                }
                if(j+i<n) {
                    dp[j][j+i+1] = max(dp[j][j+i+1], dp[j][j+i]+a[j+i]);
                }
            } else {
                if(j>0) {
                    dp[j-1][j+i] = min(dp[j-1][j+i], dp[j][j+i]);
                }
                if(j+i<n) {
                    dp[j][j+i+1] = min(dp[j][j+i+1], dp[j][j+i]);
                }
            }

            
            
        }
        x ^= 1;
    }


    cout << 2*dp[0][n] - sum << '\n';
}