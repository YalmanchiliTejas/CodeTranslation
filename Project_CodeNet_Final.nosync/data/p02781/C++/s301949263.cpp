#include <bits/stdc++.h>
using namespace std;
#define int long long

// 基本的には一番上の桁から下りながら, 1-9をそれぞれ調べていく.
// i桁目までの結果smallerだったテーブルは(i+1)はどうやってもsmaller.
// i桁目までsmallerではないつまりsameだった場合,
//      Nのi桁目より小さいものを選べば
//          i+1はsmaller
//      Nのi桁目と同じものを選べば
//          i+1はsame
//
// 初期条件は dp[0桁目][same][ng] = 1
// dp[i][smaller][ok] = i桁目まで見た時にsmallerでokだったものの数.

// 桁 / smaller(else: same) / ok
int dp[101][2][5];
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string N;
    int K;
    cin >> N >> K;
    int l = N.length();
    vector<int> n;
    for (auto c: N) {
        n.push_back(c - '0');
    }
    // 桁 smaller
    dp[0][0][0] = 1;
    for (int i = 0; i < l; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int k = 0; k <= K; k++) {
                for (int x = 0; x <= (smaller ? 9 : n[i]); x++) {
                    int next_smaller = (int)(smaller || x < n[i]);
                    int next_k = k + (int)(x != 0);
                    dp[i + 1][next_smaller][next_k] += dp[i][smaller][k];
                }
            }
        }
    }
    cout << dp[l][0][K] + dp[l][1][K] << endl;
    return 0;
}

