#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int COMMAX = 200000;
const int MOD = 1000000007;
vector<long long> fac, finv, inv;

void InitializeCombination(void){
    fac.push_back(1LL);
    fac.push_back(1LL);
    finv.push_back(1LL);
    finv.push_back(1LL);
    inv.push_back(0LL); //Though 0^(-1) cannot be defined, there should be some number in inv[0]
    inv.push_back(1LL);
    for (int i = 2; i < COMMAX; i++){
        fac.push_back(fac[i-1] * (long long)i % (long long)MOD);
        inv.push_back((long long)MOD - inv[MOD%i] * (long long)(MOD/i) % (long long)MOD);
        finv.push_back(finv[i-1] * inv[i] % (long long)MOD);
    }
}

long long Combination(int n, int r){
    if (n < r) return 0LL;
    if (n < 0 || r < 0) return 0LL;
    return fac[n] * (finv[r] * finv[n-r] % MOD) % MOD;
}

int main(void){
    int N, M, K;
    cin >> N >> M >> K;

    InitializeCombination();

    long long sumCost = 0;

    for(int i=1; i<N; i++){
        sumCost += (long long)(N-i)*M*M%MOD*i%MOD;
        sumCost = sumCost % MOD;
    }
    for(int i=1; i<M; i++){
        sumCost += (long long)(M-i)*N*N%MOD*i%MOD;
        sumCost = sumCost % MOD;
    }

    sumCost = (sumCost*Combination(N*M-2, K-2))%MOD;

    cout << sumCost << endl;

    return 0;
}