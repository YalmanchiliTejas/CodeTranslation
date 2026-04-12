#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<map<int, ll>>> dp(N+1, vector<map<int, ll>>(2));
    vector<vector<map<int, bool>>> flg(N+1, vector<map<int, bool>>(2));
    dp[0][0][0] = 0;

    rep(i, N) {
        rep(j, 2) {
            for (auto &p : dp[i][j]) {
                int k = p.first, ni = i+1, nk = k;
                rep(nj, 2) {
                    if (j && nj) continue;
                    if (nj) nk++;
                    
                    if (nk < (ni-1)/2 || (ni+1)/2 < nk) continue;

                    if (nj) {
                        if (dp[ni][nj].count(nk)) chmax(dp[ni][nj][nk], dp[i][j][k] + A[i]);
                        else dp[ni][nj][nk] = dp[i][j][k] + A[i];
                    } else {
                        if (dp[ni][nj].count(nk)) chmax(dp[ni][nj][nk], dp[i][j][k]);
                        else dp[ni][nj][nk] = dp[i][j][k];
                    }
                }
            }
        }
    }

    ll ans = max(dp[N][0][N/2], dp[N][1][N/2]);
    cout << ans << endl;
}