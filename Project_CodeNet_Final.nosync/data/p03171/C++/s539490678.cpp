#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    int N; cin >> N;
    ll a[N]; rep(i, N) cin >> a[i];
    ll dp[N + 1][N + 1]; //dp[i][j] : [i, j) において最適な行動におけるスコア
    rep(i, N + 1) dp[i][i] = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j + i <= N; ++j) {
            if((N - i) % 2 == 0) {
                dp[j][j + i] = max(dp[j][i + j - 1] + a[i + j - 1], dp[j + 1][i + j] + a[j]);
            }else {
                dp[j][j + i] = min(dp[j][i + j - 1] - a[i + j - 1], dp[j + 1][i + j] - a[j]);
            }
        }
    }
    cout << dp[0][N] << endl;
}
