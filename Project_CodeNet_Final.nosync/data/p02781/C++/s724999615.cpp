#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <functional>
#include <cstring>
#include <regex>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revrep(i, n) for (int i = (n); i >= 0; i--)
#define revrepr(i, a, b) for (int i = (a); i >= b; i--)
#define debug(x) cerr << #x << ": " << x << "\n"

using ll = long long;
using P = pair<int, int>;

const long long MOD = 1e9+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class T>
istream& operator >>(istream &is, vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) cin >> v.at(i);
    return is;
}

//dp[i][j][k] i桁目 0でない数がk個 k 0: 上位桁が一致 1: 小さい
ll dp[101][4][2];

int main() {
    string s;
    int k;
    cin >> s >> k;
    int len = s.size();

    dp[0][0][0] = 1;
    //dp[0][0][1] = 1;
    rep(i, len) {
        int digit = s.at(i) - '0';

        //0
        rep(j, 4) {
            if (digit == 0) {
                dp[i + 1][j][0] += dp[i][j][0];
                dp[i + 1][j][1] += dp[i][j][1];
            }
            else { //0 < digit
                dp[i + 1][j][1] += dp[i][j][0];
                dp[i + 1][j][1] += dp[i][j][1];
            }
        }

        repr(num, 1, 10) {
            if (num < digit) {
                rep(j, 3) {
                    dp[i + 1][j + 1][1] += dp[i][j][0];
                    dp[i + 1][j + 1][1] += dp[i][j][1];
                }
            }
            else if (num == digit) {
                rep (j, 3) {
                    dp[i + 1][j + 1][0] += dp[i][j][0];
                    dp[i + 1][j + 1][1] += dp[i][j][1];
                }
            }
            else { //num > digit
                rep(j, 3) {
                    dp[i + 1][j + 1][1] += dp[i][j][1];
                }
            }
        }
    }

    ll res = dp[len][k][0] + dp[len][k][1];
    cout << res << endl;
}