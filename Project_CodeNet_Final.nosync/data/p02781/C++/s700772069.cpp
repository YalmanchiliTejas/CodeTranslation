// 6/23 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string N;
vector<int> n;
int dp[110][2][5];

int main() {
    cin >> N;
    int K;
    cin >> K;

    // int size = N.size();
    for (auto a : N) {
        n.push_back(a-'0');
    }
    int l = n.size();

    dp[0][0][0] = 1;  // 初期条件

    for (int i = 0; i < l; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int k = 0; k <= K; k++) {
                for (int x = 0; x <= (smaller ? 9 : n[i]); x++) {
                    if (x==0) dp[i + 1][smaller || x < n[i]][k] += dp[i][smaller][k];
                    else dp[i + 1][smaller || x < n[i]][k + 1] += dp[i][smaller][k];   
                }
            }
        }
    }

    cout << dp[l][0][K] + dp[l][1][K] << endl;
}