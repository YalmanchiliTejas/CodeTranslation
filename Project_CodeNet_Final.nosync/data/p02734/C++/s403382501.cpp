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
        for(int j = s; j >= 0; j--) {
            if (dp[j] > 0 && j+arr[i] <= s) {
                dp[j+arr[i]] += dp[j];
                dp[j+arr[i]] %= mod;
            }
        }
        if (arr[i] <= s) { // multiply first element to extend LHS
            dp[arr[i]] += i+1;
        }
        ans += dp[s]; // extend right each time
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}


