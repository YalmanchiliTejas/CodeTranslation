#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'

const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string s;
    int D;
    cin >> s >> D;

    int n = s.size();
    ll dp[n+1][2][D]; //桁、フラグ、Dで割ったあまり　:= 総数

    memset(dp,0,sizeof(dp));
    dp[0][0][0] = 1;

    for(int i = 0; i < n; i++){
        int p = s[i] - '0';
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < D; k++){
                for(int l = 0; l <= (j ? 9 : p); l++){
                    dp[i+1][j || (l < p)][(k + l) % D] += dp[i][j][k];
                    dp[i+1][j || (l < p)][(k + l) % D] %= MOD;
                }
            }
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0] - 1 + MOD ) % MOD << endl;
}

