#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

ll dp[102][2][102];
int main()
{
    string N;
    cin >> N;
    int K, len = (int)N.size();
    cin >> K;

    dp[0][0][0] = 1;
    rep(i, len) {
        int D = N[i] - '0';
        rep(j, 2) {
            rep(k, 101) {
                for (int d = 0; d <= (j ? 9 : D); d++) {
                    dp[i + 1][j || (d < D)][k + (d ? 1 : 0)] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[len][0][K] + dp[len][1][K] << endl;
    return 0;
}