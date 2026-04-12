#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll dp[110][2][10];

int main() {
    string n;
    int k;
    cin >> n >> k;

    dp[0][0][0] = 1;
    int l = n.size();
    for (int i = 0; i < l; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j <= 3; j++) {
                for (int x = 0; x <= (smaller ? 9 : (int)(n[i] - '0')); x++) {
                    dp[i + 1][smaller || x < (int)(n[i] - '0')][j + (x != 0)] += dp[i][smaller][j];
                }
            }
        }
    }
    cout << dp[l][0][k] + dp[l][1][k] << endl;
}