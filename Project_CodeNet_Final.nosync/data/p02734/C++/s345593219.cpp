#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
using ll = long long;

constexpr int P = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    ll r = 0;
    vector<int> dp(s + 1, 0);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        dp[0]++;
        for (int j = s; j >= a; j--) {
            dp[j] += dp[j - a];
            if (dp[j] >= P) dp[j] -= P;
        }
        r += dp[s];
    }

    cout << r % P << endl;

    return 0;
}