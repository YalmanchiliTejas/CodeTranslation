#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string n;
    cin >> n;
    int K;
    cin >> K;
    int size = n.length();
    int dp[105][4][2] = {0};
    dp[0][0][0] = 1;
    rep(i, size) rep(j, 4) rep(k, 2){
        int nd = n[i] - '0';
        rep(d, 10) {
            int ni = i+1, nj = j, nk = k;
            if ( d != 0 ) ++nj;
            if ( nj > K ) continue;
            if ( k == 0 ) {
                if ( d > nd ) continue;
                if ( d < nd ) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[size][K][0] + dp[size][K][1] << endl;
    return 0;
}
