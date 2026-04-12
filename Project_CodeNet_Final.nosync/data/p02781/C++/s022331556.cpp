#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

ll dp[111][2][4];

int getNum(char c) {
    return (int)(c - '0');
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    int K;
    cin >> S >> K;
    int N = (int)S.size();
    dp[0][0][0] = 1;
    rep(i, 0, N) rep(j, 0, 2) rep(k, 0, K + 1) {
        int max_d = j ? 10 : getNum(S[i]) + 1;
        rep(d, 0, max_d) {
            if (k + (d > 0) > K) {
                continue;
            }
            dp[i + 1][j | (getNum(S[i]) > d)][k + (d > 0)] += dp[i][j][k];
        }
    }
    cout << dp[N][0][K] + dp[N][1][K] << endl;
    return 0;
}