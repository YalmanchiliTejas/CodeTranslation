#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int d;
    cin >> d;
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(d, vector<ll>(2, 0)));
    rep(i, s[0]-'0'+1){
        if(i == s[0]-'0'){
            dp[0][i%d][1] = 1;
        }else{
            dp[0][i%d][0]++;
        }
    }
    ll mod = 1000000007;
    for(int i = 1; i < n; i++){
        rep(j, d){
            rep(k, 10){
                (dp[i][(j+k)%d][0] += dp[i-1][j][0]) %= mod;
            }
        }
        rep(j, d){
            rep(k, s[i]-'0'){
                (dp[i][(j+k)%d][0] += dp[i-1][j][1]) %= mod;
            }
        }
        rep(j, d){
            (dp[i][(j+(s[i]-'0'))%d][1] += dp[i-1][j][1]) %= mod;
        }
    }
    ll ans = (dp[n-1][0][0] + dp[n-1][0][1] - 1 + mod) % mod;
    cout << ans << endl;
}