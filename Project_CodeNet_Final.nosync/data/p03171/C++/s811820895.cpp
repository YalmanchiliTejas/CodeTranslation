#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
const int MOD = 1000000007;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

    for (int len=1;len<=n;++len) {
        for (int i=0;i<=(n-len);++i) {
            int j = i + len;

            // 先手の場合。
            if ((n - len) % 2 == 0) {
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]); // 先頭を取る場合と、末尾を取る場合の大きい方。
            // 後手の場合。
            } else {
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
            }
        }
    }

    cout << dp[0][n] << endl;
}
