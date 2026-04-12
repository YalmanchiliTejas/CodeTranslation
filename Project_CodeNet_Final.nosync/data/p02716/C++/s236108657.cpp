#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll dp[200010][2][2];

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < 200010; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = -LINF;
            }
        }
    }
    dp[0][0][0] = 0;
    dp[0][1][0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (i%2){
            dp[i][0][0] = max(dp[i-1][1][1], dp[i-1][1][0]);
            if (i > 1) dp[i][0][1] = dp[i-1][0][0] + a[i-1];
            dp[i][1][1] = dp[i-1][1][0] + a[i-1];
        } else{
            dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][0][1]);
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1]);
            dp[i][1][1] = dp[i-1][0][0] + a[i-1];
        }
    }
    if (n%2){
        cout << max(dp[n][0][0], dp[n][0][1]) << endl;
    } else{
        cout << max(dp[n][1][0], dp[n][1][1]) << endl;
    }
}
