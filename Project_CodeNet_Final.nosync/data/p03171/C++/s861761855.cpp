#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
vector<long long> a(3030, 0);
long long dp[3030][3030];

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a.at(i);

    for(int i = 0; i <= n; ++i) dp[i][i] = 0;

    for(int len = 1; len <= n; ++len) {
        for(int i = 0; i+len <= n; ++i) {
            int j = i + len;

            if((n-len) % 2 == 0) {
                dp[i][j] = max(dp[i+1][j]+a.at(i), dp[i][j-1]+a.at(j-1));
            }else {
                dp[i][j] = min(dp[i+1][j]-a.at(i), dp[i][j-1]-a.at(j-1));
            }
        }
    }

    cout << dp[0][n] << endl;
}