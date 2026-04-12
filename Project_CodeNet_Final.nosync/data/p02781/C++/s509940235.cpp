#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int K;
    cin >> s >> K;
    
    int n = s.size();
    ll dp[101][2][5] = {0};
    dp[0][0][0] = 1;

    rep(i, n){
        rep(j, 2){
            rep(k, K+1){
                
                int c = s[i] - '0';
                rep(nxt, 10){
                    if(c<nxt && j==0) continue;

                    int dgt = i + 1;

                    int isless = j;
                    if(nxt < c) isless = 1;
                    
                    int k2 = k;
                    if(nxt != 0) ++k2;

                    dp[i + 1][isless][k2] += dp[i][j][k];

                }
            }
        }
    }

    cout << dp[n][0][K] + dp[n][1][K] << endl;

    return 0;
}