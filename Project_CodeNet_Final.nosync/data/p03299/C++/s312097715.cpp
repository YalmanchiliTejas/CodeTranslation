#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n, k;
int hs[105];
int cp[105];
int dp[105][105];

const int mod = 1e9 + 7;

void add(int &x, llong y) {
    x += y % mod;
    x %= mod;
}

int mul(int x, int y) {
    return (llong)x * y % mod;
}

int pw(int x, int p) {
    if (p == 0) return 1;
    int ret = pw(x, p >> 1);
    ret = mul(ret, ret);
    if (p & 1) ret = mul(ret, x);
    return ret;
}

int solve(int s, int e) {
    dp[s - 1][0] = 1;
    for (int i = s; i <= e; ++i) {
        if (hs[i - 1] < hs[i]) {
            dp[i][0] = dp[i - 1][0];
            add(dp[i][0], dp[i][0]);
            
            for (int j = 1; j <= hs[i - 1]; ++j) {
                dp[i][j] = mul(dp[i - 1][j], pw(2, cp[hs[i]] - cp[hs[i - 1]]));
            }
            for (int j = hs[i - 1] + 1; j <= hs[i]; ++j) {
                dp[i][j] = mul(dp[i - 1][0], mul((pw(2, cp[j] - cp[j - 1]) + mod - 1 - (j == 1 ? pw(2, cp[j] - 1) : 0)) % mod, pw(2, cp[hs[i]] - cp[j] + 1)));
            }
        }
        else {
            dp[i][0] = dp[i - 1][0];
            for (int j = hs[i] + 1; j < k; ++j) {
                add(dp[i][0], dp[i - 1][j]);
            }
            add(dp[i][0], dp[i][0]);
            for (int j = 1; j <= hs[i]; ++j) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < k; ++i) {
        add(ret, dp[e][i]);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    vector<int> one;
    one.push_back(0);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", hs + i);
        if (hs[i] == 1) hs[i] = 0, one.push_back(i);
        cp[i] = hs[i];
    }
    one.push_back(n + 1);
    sort(cp, cp + (n + 1));
    k = unique(cp, cp + (n + 1)) - cp;
    for (int i = 1; i <= n; ++i) {
        hs[i] = lower_bound(cp, cp + k, hs[i]) - cp;
    }
    int ret = pw(2, one.size() - 2);
    for (int i = 1; i < one.size(); ++i) {
        ret = mul(ret, solve(one[i - 1] + 1, one[i] - 1));
    }
    printf("%d\n", ret);
	return 0;
}
