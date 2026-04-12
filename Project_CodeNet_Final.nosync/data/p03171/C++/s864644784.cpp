//
// Created by Hideaki Imamura on 2020-03-17.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
//const ll mod = 1000000007;

int N;
ll a[3100];
ll dp[3100][3100];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];

    // dp[i][j] = 元の数列から連続する区間[i,j)をとった局面からスタートした時、X-Yの値
    for (int i = 0; i < N; ++i) dp[i][i] = 0;

    for (int len = 1; len <= N; ++len) {
        for (int i = 0; i + len <= N; ++i) {
            int j = i + len;
            if ((N - len) % 2 == 0) {
                dp[i][j] = dp[i+1][j] + a[i];
                chmax(dp[i][j], dp[i][j-1] + a[j-1]);
            } else {
                dp[i][j] = dp[i+1][j] - a[i];
                chmin(dp[i][j], dp[i][j-1] - a[j-1]);
            }
        }
    }

    cout << dp[0][N] << endl;
    return 0;
}