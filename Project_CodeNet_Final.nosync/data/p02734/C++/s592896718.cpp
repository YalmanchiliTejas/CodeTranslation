#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>
#define PI 3.141592653589793

int main() {
    ll n, s, mod = 998244353;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll dp[n + 1][s + 1][3] = {};
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i + 1][j][0] = dp[i][j][0];
            dp[i + 1][j][1] = dp[i][j][0] + dp[i][j][1];
            dp[i + 1][j][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            dp[i + 1][j][1] %= mod;
            dp[i + 1][j][2] %= mod;
            if (j >= a[i]) {
                dp[i + 1][j][1] += dp[i][j - a[i]][0] + dp[i][j - a[i]][1];
                dp[i + 1][j][2] += dp[i][j - a[i]][0] + dp[i][j - a[i]][1];
                dp[i + 1][j][1] %= mod;
                dp[i + 1][j][2] %= mod;
            }
        }
    }

    cout << dp[n][s][2] << endl;
}
