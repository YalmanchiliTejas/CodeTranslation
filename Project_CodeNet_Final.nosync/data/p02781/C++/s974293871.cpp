#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

ll dp[110][4][2];

int main() {
    string N;
    int K;
    cin >> N >> K;
    dp[0][0][1] = 1;
    for(int i = 0; i < N.size(); i++) {
        for(int k = 0; k < 4; k++) {
            for(int j = 0; j < 2; j++) {
                if(j) { // smallが確定していない
                    int n = N[i] - '0';
                    if(n == 0) {
                        dp[i + 1][k][j] += dp[i][k][j];
                    } else {
                        if(k < 3)
                            dp[i + 1][k + 1][j] += dp[i][k][j];
                    }
                    if(k < 3)
                        dp[i + 1][k + 1][!j] += dp[i][k][j] * max(0, (n - 1));
                    if(n != 0)
                        dp[i + 1][k][!j] += dp[i][k][j];
                } else { // smallが確定している
                    if(k < 3)
                        dp[i + 1][k + 1][j] += dp[i][k][j] * 9;
                    dp[i + 1][k][j] += dp[i][k][j];
                }
            }
        }
    }
    cout << dp[N.size()][K][0] + dp[N.size()][K][1] << endl;
    return 0;
}