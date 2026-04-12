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
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(3, -LINF));
    dp[0][1] = 0;
    dp[1][1] = 0;
    dp[1][2] = a[1];
    for(int i=2;i<=n;++i) {
        if(i % 2) {
            dp[i][1] = max(dp[i-1][1], dp[i-2][1] + a[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-2][2] + a[i]);
        } else {
            dp[i][0] = max(dp[i-1][1], dp[i-2][0] + a[i]);
            dp[i][1] = max(dp[i-1][2], dp[i-2][1] + a[i]);
        }
    }
    cout << dp[n][1] << endl;
}
