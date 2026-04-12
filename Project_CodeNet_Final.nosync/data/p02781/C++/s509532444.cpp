#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'

ll dp[110][2][4]; // 桁、N未満フラグ、出現する0以外の個数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string s;
    int K;
    cin >> s >> K;

    rep(i,110){
        rep(j,2){
            rep(k,4) dp[i][j][k] = 0;
        }
    }
    dp[0][0][0] = 1;
    int n = s.size();
    for(int i = 0; i < n; i++){
        int D = s[i] - '0';
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 4; k++){
                for(int d = 0; d <= (j ? 9 : D); d++){
                    if(d != 0){
                        if(k + 1 > K) continue;
                        dp[i+1][j || (d < D)][k+1] += dp[i][j][k];
                    } else {
                        dp[i+1][j || (d < D)][k] += dp[i][j][k];
                    }
                }
            }
        }
    }
    cout << dp[n][1][K] + dp[n][0][K] << endl;
}

