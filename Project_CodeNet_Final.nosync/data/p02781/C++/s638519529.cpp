#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define reps(i,s,n) for (int i = s; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define per1(i,n) for (int i = n; i >= 1; --i)
#define all(c) begin(c),end(c)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
// if(nextH >= 0 && nextH < H && nextW >= 0 && nextW < W)
static const long double pi = acos(-1.0);
typedef complex<ld> cd;

ll dp[105][4][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string N; cin >> N;
    int n = N.size();
    int K; cin >> K;
    dp[0][0][0] = 1;

    rep(i, n) {
        rep(j, K + 1) {
            rep(k, 2) {
                int nd = N[i] - '0';
                rep(d, 10) {
                    if((j + (d != 0)) > K) continue; // 非0がKを超えてしまう
                    if(!k && d > nd) continue;

                    dp[i + 1][j + (d != 0)][k || d < nd] += dp[i][j][k];
                }
            }
        }
    }

    ll ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;

    return 0;
}
