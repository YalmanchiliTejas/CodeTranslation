#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

ll dp[101][5][2];  // dp[i][j][k]: i桁目までで0でない数字がj個あって(k ? N未満 : Nと同じ)通り数

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    int K;
    cin >> S >> K;
    int N = (int)S.size();
    dp[0][0][0] = 1;
    rep(i, 0, N) rep(j, 0, K + 1) rep(k, 0, 2) {
        int D = (int)(S[i] - '0') + 1;
        if (k) {
            D = 10;
        }
        rep(d, 0, D) {
            dp[i + 1][j + (int)(d != 0)][k || (d + 1 < D)] += dp[i][j][k];
        }
    }
    cout << dp[N][K][0] + dp[N][K][1] << endl;
    return 0;
}