#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length(), k;
    cin >> k;

    ll dp[n+1][4][2]; // {idx, kをいくら消費したか？, s未満確定？}
    fill_n(dp[0][0], (n+1)*4*2, 0LL);
    if(s[0] != '0') {
        dp[0][1][1] += int(s[0]-'0')-1;
        dp[0][1][0] = 1;
        dp[0][0][1] = 1;
    } else {
        dp[0][0][0] = 1;
    }

    for(int i=1;i<n;++i) {
        for(int j=0;j<=k;++j) {
            // 1-9
            if(j < k) {
                dp[i][j+1][1] += 9*dp[i-1][j][1];
                if(s[i] != '0') {
                    dp[i][j+1][1] += (int(s[i]-'0')-1) * dp[i-1][j][0];
                    dp[i][j+1][0] += dp[i-1][j][0];
                }
            }
            // 0
            dp[i][j][1] += dp[i-1][j][1];
            if(s[i] != '0') {
                dp[i][j][1] += dp[i-1][j][0];
            } else {
                dp[i][j][0] += dp[i-1][j][0];
            }
            // cerr << i << "," << j << ": " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }

    cout << dp[n-1][k][0]+dp[n-1][k][1] << endl;
}
