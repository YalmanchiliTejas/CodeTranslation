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
    string s;
    cin >> s;
    int k;
    cin >> k;

    int num = s.size();
    vvi dp(num+1, vi(k+1));
    vi dp_(num+1);
    rep(i, num) {
        dp_[i+1] = dp_[i];
        int now = s[i] - '0';
        if(s[i] != '0') {
            dp_[i+1]++;
            if(dp_[i] < k) {
                dp[i+1][dp_[i]+1] = now-1;
            }
            if(dp_[i] <= k) {
                dp[i+1][dp_[i]]++;
            }
        } 
        rep(j, k) {
            dp[i+1][j+1] += dp[i][j] * 9;
        }
        rep(j, k+1) {
            dp[i+1][j] += dp[i][j];
        }
    }

    if(dp_[num] == k) {
        dp[num][k]++;
    }
    cout << dp[num][k] << endl;
}