#include <bits/stdc++.h>
using namespace std;

int64_t MOD;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int nth_bit(int64_t num, int n){
    return (num >> n) & 1;
}

int main(){
    int N, K;
    cin >> N >> K >> MOD;

    static int64_t dp[201][11][2048], dp2[201][11][2048];
    dp[0][1][1] = 1;
    int B = 1<<(K+1);
    for(int t=0; t<N; t++){
        memset(dp2, 0, sizeof(dp2));
        for(int i=0; i<2*N; i++) for(int j=1; j<=K; j++) for(int b=0; b<B; b++){
            if(dp[i][j][b] == 0) continue;
            int ad = 0;
            while(nth_bit(b, ad)) ad++;
            if(ad > K) continue;
            int i2 = i+ad;
            int b2 = (b>>ad) + 1;
            for(int j2=1; j2<=K; j2++){
                if(nth_bit(b2, j2)) continue;
                if(i2+j2-i-j > K) continue;
                if(i2+j2 <= i+j) continue;
                if(i2+j2 > 2*N) continue;
                add(dp2[i2][j2][b2|(1<<j2)], dp[i][j][b]);
            }
        }
        for(int i=0; i<2*N; i++) for(int j=1; j<=K; j++) for(int b=0; b<B; b++) dp[i][j][b] = dp2[i][j][b];
    }

    int64_t ans = 0;
    for(int i=0; i<2*N; i++) for(int j=1; j<=K; j++) for(int b=0; b<B; b++) add(ans, dp[i][j][b]);
    cout << ans << endl;
    return 0;
}

