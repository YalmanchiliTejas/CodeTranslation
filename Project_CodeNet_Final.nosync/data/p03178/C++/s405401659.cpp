#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll MOD = ll(1e9 + 7);

ll solve(string s, int D){
    int L = s.size();
    ll dp[2][2][100]{};  // dp[桁][最大未満フラグ][桁和 mod D]
    dp[0][0][0] = 1;
    for(int i=0;i<L;i++){
        int M = s[i]-'0';
        for(int j=0;j<2;j++){
            for(int k=0;k<D;k++){
                for(int m=0;m<=(j?9:M);m++){
                    dp[1][j||(m<M)][(k+m)%D] += dp[0][j][k];
                }
            }
        }
        for(int j=0;j<2;j++){
            for(int k=0;k<D;k++){
                dp[0][j][k] = dp[1][j][k] % MOD;
                dp[1][j][k] = 0;
            }
        }
    }
    
    return (dp[0][1][0] + dp[0][0][0] - 1 + MOD)%MOD;
}

int main() {
    string K;
    int D;
    cin >> K >> D;
    cout << solve(K, D) << endl;
    return 0;
}
