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
        for (int smaller = 0; smaller < 2; ++smaller) {
            for (int cnt = 0; cnt <= k; ++cnt) {
                for (int x = 0; x <= (smaller ? 9 : n[i] - '0'); ++x) {
                    dp[i + 1][smaller || x < (n[i] - '0')][cnt + (x > 0 ? 1 : 0)] += dp[i][smaller][cnt];
                }
            }
        }
    }
    cout << dp[l][0][k] + dp[l][1][k] << endl;

    return 0;
}