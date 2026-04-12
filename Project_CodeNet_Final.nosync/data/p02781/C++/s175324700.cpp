#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string N;
    ll K;
    cin >> N >> K;

    while (N.size() < 100) {
        N = '0' + N;
    }

    ll dp[101][2][4];

    Rep (i, 101) Rep (j, 2) Rep (k, 4) dp[i][j][k] = 0;
    dp[0][0][0] = 1;

    Rep (i, 100) {
        // smaller 1 to 1
        Rep (j, 4) {
            dp[i+1][1][j] += dp[i][1][j];
        }
        Rep (j,3) {
            dp[i+1][1][j+1] += 9 * dp[i][1][j];
        }

        // smaller 0 to 0
        if (N[i] == '0') {
            Rep (j, 4) dp[i+1][0][j] += dp[i][0][j];
        } else {
            Rep (j, 3) dp[i+1][0][j+1] += dp[i][0][j];
        }

        // smaller 0 to 1
        ll now = N[i] - '0';
        if (now != 0) {
            Rep (j, 4) dp[i+1][1][j] += dp[i][0][j];
            Rep (j, 3) dp[i+1][1][j+1] += (now - 1) * dp[i][0][j];
        }
    }

    // for (int i = 90; i <= 100; i++) {
    //     Rep (j, 4) {
    //         cout << dp[i][1][j] << " \n"[j==3];
    //     }
    // }

    cout << dp[100][0][K] + dp[100][1][K] << "\n";
}