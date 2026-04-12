#include <bits/stdc++.h>
using namespace std;



int main(){
    string N;
    int K;
    cin >> N;
    cin >> K;
    
    int keta = N.size();
    int dp[105][4][2];
    for (int i=0; i<105; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<2; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;

    for (int i=0; i<keta; i++) {
        for (int j=0; j<K+1; j++) {
            for (int k=0; k<2; k++) {
                int nd = N[i] - '0';
                for (int d=0; d<10; d++) {
                    int ni = i+1;
                    int nj = j;
                    int nk = k;
                    if (d!=0) { nj++; }
                    if (nj>K) { continue; }
                    if (k==0) {
                        if (d<nd) { nk=1; }
                        else if (d>nd) { continue; }
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    
    int ans = dp[keta][K][0] + dp[keta][K][1];
    std::cout << ans << std::endl;
    
    
    return 0;
}
