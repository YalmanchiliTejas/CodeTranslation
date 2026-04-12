#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll INF = 1145141919810364364;

void chmax(ll &x, ll val) {
    x = max(x, val);
}

int main() {
    int n;
    cin >> n;
    int extra = n % 2 + 1;
    vector<vector<ll>> dp(n + 10, vector<ll>(extra + 1, -INF));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= extra; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 10; i < n + 10; i++) {
        ll a;
        cin >> a;
        for (int j = 0; j <= extra; j++) {
            for (int k = 0; k + j <= extra; k++) {
                chmax(dp[i][k + j], dp[i - (j + 2)][k] + a);
            }
        }
    }

    ll ret = -INF;
    for (int i = 0; i <= extra; i++) {
        for (int j = 0; i + j <= extra; j++) {
            chmax(ret, dp[n + 9 - j][i]);
        }
    }
    cout << ret << endl;
    return 0;
}