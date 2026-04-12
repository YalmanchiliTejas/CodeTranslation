#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if(n % 2 == 0){
        vector<ll> dp1(n, 0), dp2(n, 0);
        dp1[0] = a[0];
        dp2[n-1] = a[n-1];
        for(int i = 1; i < n; i++){
            if(i % 2 == 0)dp1[i] = dp1[i-1] + a[i];
            else dp1[i] = dp1[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            if(i % 2 == 1)dp2[i] = dp2[i+1] + a[i];
            else dp2[i] = dp2[i+1];
        }
        ll ans = max(dp2[0], dp1[n-1]);
        for(int i = 1; i < n-1; i++){
            ans = max(ans, dp1[i-1]+dp2[i+1]);
        }
        cout << ans << endl;
    }else{
        vector<vector<ll>> dp1(n, vector<ll>(2, 0));
        dp1[0][0] = a[0];
        for(int i = 1; i < n; i++){
            if(i % 2 == 1){
                dp1[i][0] = dp1[i-1][0];
                dp1[i][1] = dp1[i-1][1] + a[i];
                if(i >= 2)dp1[i][1] = max(dp1[i][1], dp1[i-2][0] + a[i]);
            }else{
                dp1[i][0] = dp1[i-1][0] + a[i];
                dp1[i][1] = dp1[i-1][1];
            }
        }
        vector<vector<ll>> dp2(n, vector<ll>(2, 0));
        dp2[n-1][0] = a[n-1];
        for(int i = n-2; i >= 0; i--){
            if(i % 2 == 1){
                dp2[i][0] = dp2[i+1][0];
                dp2[i][1] = dp2[i+1][1] + a[i];
                if(i <= n-3)dp2[i][1] = max(dp2[i][1], dp2[i+2][0]+a[i]);
            }else{
                dp2[i][0] = dp2[i+1][0] + a[i];
                dp2[i][1] = dp2[i+1][1];
            }
        }

        ll ans = -1001001001001001001;
        rep(i, n){
            if(i == 0){
                ans = max(ans, dp2[2][0]);
                ans = max(ans, dp2[1][1]);
            }else if(i == n-1){
                ans = max(ans, dp1[n-3][0]);
                ans = max(ans, dp1[n-2][1]);
            }else if(i % 2 == 0){
                ans = max({ans, dp1[i-1][0]+dp2[i+1][0], dp1[i-1][0]+dp2[i+1][1]});
                ans = max({ans, dp1[i-1][1]+dp2[i+1][0], dp1[i-1][1]+dp2[i+1][1]});
            }else{
                ans = max({ans, dp1[i-1][0]+dp2[i+1][1], dp1[i-1][1]+dp2[i+1][0]});
                ans = max(ans, dp1[i-1][1]+dp2[i+1][1]+a[i]);
            }
        }
        cout << ans << endl;
    }
    
}