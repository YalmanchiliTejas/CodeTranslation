#include <iostream>
#include <string>
#include <vector>
#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
int N, X;
long long BG[60][2];
long long dp(int n, long long x) {
    if(BG[n][0] <= x) {
        return BG[n][1];
    }
    if(x == 1) {
        return 0;
    } else if(x <= 1 + BG[n - 1][0]) {
        return dp(n - 1, x - 1);
    } else if(x == 2 + BG[n - 1][0]) {
        return BG[n - 1][1] + 1;
    } else if(x <= 2 + BG[n - 1][0] * 2) {
        return BG[n - 1][1] + 1 + dp(n - 1, x - 2 - BG[n - 1][0]);
    } else {
        return BG[n][1];
    }
}
int main() {
    int N;
    long long X;
    cin >> N >> X;

    BG[0][0] = 1;
    BG[0][1] = 1;
    rep(i, 1, N + 1) {
        BG[i][0] = BG[i - 1][0] * 2 + 3;
        BG[i][1] = BG[i - 1][1] * 2 + 1;
    }
    // cout << BG[N][0] << endl;
    // cout << BG[N][1] << endl;

    cout << dp(N, X) << endl;
}
