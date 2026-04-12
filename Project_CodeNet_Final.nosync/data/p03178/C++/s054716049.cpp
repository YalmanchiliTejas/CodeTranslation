#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);
// https://youtu.be/FAQxdm0bTaw?t=11830
int main() {
    string s;
    int D;
    ll mod = 1e9 + 7;
    cin >> s >> D;
    // example 256
    // 00~24 => 0~9
    // 25 => 0~6
    vector<vector<ll>> dp(D, vector<ll>(2, 0));
    // dp[sum][less_than_prefix]: the num of ways to choose digits so far
    // such that the sum of digits %D is 'sum' and 'less_than_prefix'
    // represents if we've already chosen digits less than prefix;
    dp[0][0] = 1;
    for(int i = 0; i < s.size(); i++) {
        vector<vector<ll>> nxt_dp(D, vector<ll>(2, 0));
        for(int sum = 0; sum < D; sum++) {
            for(bool less_than_prefix: {false, true}) { // if less than prefix, we can append any digit from 0~9
                for(int digit = 0; digit < 10; digit++) {
                    if (less_than_prefix == false && digit > (s[i]-'0'))
                        break;
                    bool less_next = less_than_prefix || (digit < (s[i]-'0'));
                    nxt_dp[(sum+digit)%D][less_next] += dp[sum][less_than_prefix];
                    nxt_dp[(sum+digit)%D][less_next] %= mod;
                }
            }
        }
        swap(dp, nxt_dp);
    }
    ll ans = (dp[0][0] + dp[0][1] - 1 + mod) % mod;
    cout << ans << endl;
}


