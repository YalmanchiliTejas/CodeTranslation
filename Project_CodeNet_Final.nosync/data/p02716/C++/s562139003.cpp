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

    ll N;
    cin >> N;
    vec A(N);
    Rep (i, N) {
        cin >> A[i];
    }

    ll dp[N+2][3];
    Rep (i, N+2) {
        Rep (j, 3) {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = 0;

    Rep (i, N+1) {
        Rep (j, 3) {
            if (i+2 < N+2) chmax(dp[i+2][j], dp[i][j] + A[i]);
            if (j+1 < 3) chmax(dp[i+1][j+1], dp[i][j]);
        }
    }

    // Rep (i, N+2) {
    //     Rep (j, 3) {
    //         cout << dp[i][j] << " \n"[j==2];
    //     }
    // }

    if (N%2 == 0) {
        cout << dp[N+1][1] << endl;
    } else {
        cout << dp[N+1][2] << endl;
    }

}