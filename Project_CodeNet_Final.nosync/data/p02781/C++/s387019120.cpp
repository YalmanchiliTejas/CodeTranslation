#include <bits/stdc++.h>
using namespace std;

int main(){
    string N;
    int K;
    cin >> N >> K;
    int sz = N.size();
    static int64_t dp[102][5][2];
    dp[0][0][0] = 1;
    for(int i=0; i<sz; i++) for(int j=0; j<=K; j++) for(int k=0; k<2; k++){
        for(int l=0; l<10; l++){
            int c = N[i]-'0';
            if(k == 0 && l > c) continue;
            dp[i+1][j+(l>0)][k|(l<c)] += dp[i][j][k];
        }
    }
    int64_t ans = 0;
    for(int k=0; k<2; k++) ans += dp[sz][K][k];
    cout << ans << endl;
    return 0;
}
