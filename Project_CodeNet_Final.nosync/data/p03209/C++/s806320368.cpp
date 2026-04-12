#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, x, c;
    cin >> n >> x;
    vector<pair<ll, ll>> dp(n + 1);
    ll ans = 0;
    
    rep(i, n + 1) {
        if (i == 0) {
            dp[i] = pair<ll, ll>(1, 1);
        }
        else {
            ll total = dp[i - 1].first * 2 + 3;
            ll patty = dp[i - 1].second * 2 + 1;
            dp[i] = pair<ll, ll>(total, patty);
        }
    }
    
    c = x;
    
    if ((n == 0) && (c == 1)) {
        ans = 1;
    }
    else {
        for(ll i = n; i > 0; i--) {
            if (c > 0) {
                c--;
            }
            
            if (dp[i - 1].first <= c) {
                c -= dp[i - 1].first;
                ans += dp[i - 1].second;
            }
            else {
                continue;
            }
            
            if (c > 0) {
                c--;
                ans++;
            }
            
            if (dp[i - 1].first <= c) {
                c -= dp[i - 1].first;
                ans += dp[i - 1].second;
            }
            else {
                continue;
            }
            
            if (c > 0) {
                c--;
            }
            
            if (c <= 0) {
                break;
            }
        }
        
        if (c > 0) {
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}