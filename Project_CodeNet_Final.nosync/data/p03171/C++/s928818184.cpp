#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <functional>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define INT_MAX 2147483647
#define ll long long

#define MOD 1000000007

ll max(ll a, ll b) { return (a < b) ? b : a; }


// DP !!
int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(n);
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int f = j, l = j + i + 1;
            dp[f][l] = max(a[f] - dp[f + 1][l], a[l] - dp[f][l - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}