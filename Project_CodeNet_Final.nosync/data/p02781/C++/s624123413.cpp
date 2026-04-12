#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int dp[105][4][2];
const int ls = 0, eq = 1;
int main(){
    string IN;
    int K;
    cin >> IN >> K;

    vector<int> N;
    for (char &c : IN) N.push_back(c - '0');

    int n = N.size();

    dp[0][0][eq] = 1;

    rep(i, n) {
        int num = N[i];
        rep(j, K) {
            if (num > 0) {
                dp[i+1][j][ls] += dp[i][j][ls] + dp[i][j][eq];
                dp[i+1][j+1][ls] += dp[i][j][ls] * 9 + dp[i][j][eq] * (num-1);
                dp[i+1][j+1][eq] += dp[i][j][eq];
            } else {
                dp[i+1][j][ls] += dp[i][j][ls];
                dp[i+1][j][eq] += dp[i][j][eq];
                dp[i+1][j+1][ls] += dp[i][j][ls] * 9;
            }
        }
    }

    int ans = 0;
    rep(i, n+1) {
        rep(j, 2) ans += dp[i][K][j];
    }

    cout << ans << endl;
}