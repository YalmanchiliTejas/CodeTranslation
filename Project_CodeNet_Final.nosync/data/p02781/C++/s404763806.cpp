#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int dp[105][4][2];

int main() {
    string s;
    int K;
    cin >> s >> K;
    int digit = s.size();
    dp[0][0][0] = 1;
    rep(i, 0, digit) {
        rep(j, 0, 4) {
            rep(k, 0, 2) {
                int nd = s[i]-'0';
                rep(d, 0, 10) {
                    int ni = i+1, nj = j, nk = k;
                    if(d != 0) nj++;
                    if(nj > K) continue;
                    if(k == 0) {
                        if(d > nd) continue;
                        if(d < nd) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    int ans = dp[digit][K][0] + dp[digit][K][1];
    cout << ans << endl;
    return 0;
}