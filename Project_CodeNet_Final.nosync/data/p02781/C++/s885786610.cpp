#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> void corner(bool flg, T hoge) { if (flg) { cout << hoge << endl; exit(0); } }

const int MOD = 1000000007;
const int INF = 1 << 30;

int dp[105][4][2];

int main() {
    string S;
    int K;
    cin >> S >> K;

    int n = S.size();
    
    dp[0][0][0] = 1;

    rep(i, n) {
        rep(j, 4) {
            rep(k, 2) {
                int nd = S[i] - '0';
                rep(d, 10) {
                    int ni = i+1, nj = j, nk = k;
                    if (d > 0) nj++;
                    if (nj > K) continue;
                    if (k == 0) {
                        if (d > nd) continue;
                        if (d < nd) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;
    return 0;
}
