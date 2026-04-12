#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

string n;
int K;

ll dp[110][2][5];

int main() {
    cin >> n >> K;
    int nlen = n.length();
    // memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for(int i = 0; i < nlen; ++i) {
        int limit = n.at(i) - '0';
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k <= K; ++k) {
                for(int d = 0; d <= (j ? 9 : limit); ++d) {
                    if(d == 0) {
                        // kは増えない
                        dp[i+1][j || (d<limit)][k] += dp[i][j][k];
                    }else {
                        dp[i+1][j || (d<limit)][k+1] += dp[i][j][k];
                    }
                }
            }
        }
    }
    
    cout << dp[nlen][0][K] + dp[nlen][1][K] << endl;
}