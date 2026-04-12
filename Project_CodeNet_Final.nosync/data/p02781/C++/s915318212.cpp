#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    if(n < 4) {
        int num = stoi(s);
        int ans = 0;
        for(int i = 1; i <= num; i++) {
            string str = to_string(i);
            ll tmp = str.size();
            if(count(all(str), '0') == tmp - k) {
                ans++;
                // cout << str << endl;
            }
        }
        cout << ans << endl;
        return 0;
    }
    ll ans = 0;
    ll t = 9;
    vector<vector<vector<ll>>> dp(n + 1,
                                  vector<vector<ll>>(2, vector<ll>(4, 0)));
    for(ll i = 1; i <= n; i++) {
        dp[i][0][0] = 1;
        dp[i][0][1] = (i - 1) * t;
        dp[i][0][2] = (i - 1) * (i - 2) * t * t / 2;
        dp[i][0][3] = (i - 1) * (i - 2) * (i - 3) * t * t * t / 6;
    }
    ll c = 0;
    for(int i = 1; i <= n; i++) {
        ll m = s[i - 1] - '0';
        if(m == 0) {
            continue;
        }
        ans += (m - 1) * dp[n - i + 1][0][k - 1 - c];
        ans += dp[n - i + 1][0][k - c];
        c++;
        if(k - 1 - c < 0) {
            break;
        }
    }
    ll res = 1;
    if(c < k) {
        res = 0;
    }
    cout << ans + res << endl;
}