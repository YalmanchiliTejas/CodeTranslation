#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int MAX_N = 3010;

ll dp[MAX_N][MAX_N];

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    for(int len = 1; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {

            int j = i + len;

            if( (n-len)%2 == 0) {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            }
            else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }

        }
    }

    cout <<dp[0][n] << endl;
    return 0;
}