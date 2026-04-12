#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)
#define MAX_NM (500000)
using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

Int inv[MAX_NM];
Int Fact[MAX_NM];
Int invFact[MAX_NM];
Int N, M, K;

void init(void) {
    Fact[0] = 1;
    inv[1] = 1;
    invFact[0] = 1;

    for(Int i = 2;i <= 2*M*N;i++) {
        inv[i] = MOD - (MOD / i)*inv[MOD % i] % MOD;
    }

    for(Int i = 1;i <= 2*N*M;i++) {
        Fact[i] = (i*Fact[i-1])%MOD;
        invFact[i] = (inv[i]*invFact[i-1])%MOD;
    }
}

Int comb(int n, int k) {
    if(k < 0 || k > n)
        return 0;
    //cout<<Fact[n]<<" "<<invFact[n-k]<<" "<<invFact[k]<<endl;
    return ((Fact[n]*invFact[n-k]%MOD)*invFact[k])%MOD;
}

int main(void) {
    Int sum = 0;
    cin>>N>>M>>K;

    init();
    Int pattern = comb(N*M-2,K-2);

    for(Int d = 1;d < M;d++) {
        Int ans = ((d*(M-d)%MOD)*N%MOD)*N%MOD;
        sum = (ans + sum) % MOD;
    }
    
    for(Int d = 1;d < N;d++) {
        Int ans = ((d*(N-d) % MOD)*M%MOD)*M%MOD;
        sum = (ans + sum) % MOD;
    }

    cout<<sum*pattern%MOD<<endl;

    return 0;
}
