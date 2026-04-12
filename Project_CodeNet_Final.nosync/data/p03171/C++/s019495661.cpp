#include <algorithm>
#include <cmath>
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
typedef long long ll;

ll dp[3010][3010];
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    // dp[i][j]:=区間[i,j)の状態から出発して、両方が最善を尽くした場合のX-Yの値
    for(int len = 1; len <= N; len++) {
        for(int i = 0; i + len <= N; i++) {
            int j = i + len;
            //先手
            if((N - len) % 2 == 0) {
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
            } else {
                //後手
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
            }
        }
    }
    cout << dp[0][N] << endl;
    return 0;
}