#include <iostream>

#define P 1000000007
#define N_MAX 200001

using namespace std;

long inv[N_MAX];
long fac[N_MAX];
long finv[N_MAX];

void init(){
    inv[0] = 1;
    fac[0] = 1;
    finv[0] = 1;
    inv[1] = 1;
    fac[1] = 1;
    finv[1] = 1;
    for(int i = 2; i < N_MAX; i++){
        fac[i] = (fac[i-1]*i)%P;
        inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
        finv[i] = (finv[i-1]*inv[i])%P;
    }
}

long comb(int n, int m){
    long ans;
    ans = fac[n]*finv[m];
    ans %= P;
    ans *= finv[n-m];
    ans %= P;
    return ans;
}

int main(){
    init();
    int N, M, K;
    cin >> N >> M >> K;
    long sum = 0;
    for(long i = 1; i <= N; i++){
        for(long j = 1; j <= M; j++){
            long a = (i*(i-1)+(N-i)*(N-i+1))/2;
            long b = (j*(j-1)+(M-j)*(M-j+1))/2;
            a *= M;
            b *= N;
            sum += ((a%P)+(b%P));
            sum %= P;
        }
    }
    
    sum *= inv[2];
    sum %= P;
    long cmb = comb(N*M-2, K-2);
    long ans = sum*cmb;
    ans %= P;
    cout << ans << endl;
}