#include <iostream>

typedef long long ll;

#define P 1000000007
#define N_MAX 1001

using namespace std;

ll inv[N_MAX];
ll fac[N_MAX];
ll finv[N_MAX];
ll finv_pow[N_MAX][N_MAX];
ll dp[N_MAX][N_MAX];

void init(){
    inv[1] = 1;
    fac[0] = 1;
    fac[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    
    for(int i = 2; i < N_MAX; i++){
        fac[i] = (fac[i-1]*i)%P;
        inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
        finv[i] = (finv[i-1]*inv[i])%P;
    }

    for(int i = 0; i < N_MAX; i++){
        finv_pow[i][0] = 1;
    }

    for(int i = 0; i < N_MAX; i++){
        for(int j = 1; j < N_MAX; j++){
            finv_pow[i][j] = (finv_pow[i][j-1]*finv[i])%P;
        }
    }
    //init dp
    for(int i = 0; i < N_MAX; i++){
        dp[i][0] = 1;
    }
}

int main(){
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    init();
    for(int i = A; i <= B; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i-1][j];
            for(int k = 0; j-i*k >= 0; k++){
                if(k >= C && k <= D){
                    dp[i][j] = (dp[i][j] + (((dp[i-1][j-i*k]*finv[k])%P)*finv_pow[i][k])%P)%P;
                    //cout << finv[k] << ' ' << finv_pow[i][k] << endl;
                    //cout << i << ' ' << j << ' ' << k <<  ' ' << dp[i][j] << ' ' << dp[i-1][j-i*k] << endl;
                }
            }
        }
    }
    //cout << (finv_pow[3][1]*6)%P << endl;
    //cout << (fac[N]*dp[B-1][N])%P << endl;
    cout << (fac[N]*dp[B][N])%P << endl;
}