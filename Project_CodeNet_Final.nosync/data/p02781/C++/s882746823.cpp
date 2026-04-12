#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[105][4][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int K;
    cin >> s >> K;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,n){
        rep(j,4){
            rep(k,2){
                int ns = s[i] - '0';
                rep(l,10){
                    int ni = i + 1;
                    int nj = j;
                    int nk = k;
                    if(l != 0) nj = j + 1;
                    if(nj > K) continue;
                    if(k == 0){
                        if(l > ns) continue;
                        if(l < ns) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
    return 0;
}
