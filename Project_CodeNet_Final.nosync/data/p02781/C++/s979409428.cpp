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

ll dp[101][5][2];

int main()
{
    string N;
    int K;

    cin >> N >> K;

    dp[0][0][0] = 1;

    int len = (int)N.size();
    rep(i, len) {
        rep(j, 4) {
            rep(k, 2) {
                int D = N[i] - '0';
                for (int d = 0; d <= (k ? 9 : D); d++) {
                    dp[i + 1][j + (d != 0 ? 1 : 0)][k || (d < D)] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[len][K][1] + dp[len][K][0] << endl;


    return 0;
}