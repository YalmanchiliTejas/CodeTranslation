#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    ll mod = 998244353;
    int n, s;
    cin >> n >> s;
    vector<int> arr(n, 0);
    for(int& val: arr)
        cin >> val;
    vector<ll> dp(s+1, 0);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        vector<ll> new_dp = dp;
        for(int j = 1; j <= s; j++) {
            if (dp[j] > 0 && j+arr[i] <= s) {
                new_dp[j+arr[i]] += dp[j];
                new_dp[j+arr[i]] %= mod;
            }
        }
        if (arr[i] <= s) { // multiply first element to extend LHS
            new_dp[arr[i]] += i+1;
        }
        dp = new_dp;
        ans += dp[s]; // extend right each time
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}


