#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define INF (1 << 30)
#define INFL (1LL << 62)
#define MOD7 1000000007
#define MOD9 1000000009
#define EPS 1e-10

using ll = long long;
using ull = unsigned long long;

int dp[101][2][5];

int main() {
    string n;
    int k, l;
    cin >> n >> k;
    l = n.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < l; ++i) {
        for (int cnt = 0; cnt <= k; ++cnt) {
            if (n[i] == '0')  {
                dp[i + 1][0][cnt] += dp[i][0][cnt]; // 0
            }
            else {
                dp[i + 1][1][cnt] += dp[i][0][cnt]; // 0
                dp[i + 1][1][cnt + 1] += dp[i][0][cnt] * (n[i] - '0' - 1); // 1 ~ n[i]
                dp[i + 1][0][cnt + 1] += dp[i][0][cnt]; // n[i]
            }
            dp[i + 1][1][cnt] += dp[i][1][cnt]; // 0
            dp[i + 1][1][cnt + 1] += dp[i][1][cnt] * 9;
        }
    }
    cout << dp[l][0][k] + dp[l][1][k] << endl;

    return 0;
}