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

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

const int max_nm = 200000+10;

Int N,M,K;

Int fact[max_nm];
Int invfact[max_nm];
Int inv[max_nm];

void init(Int x) {
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    invfact[0] = invfact[1] = 1;
    
    for(int i = 2;i <= x;i++) {
        fact[i] = (i*fact[i-1] % MOD);
        inv[i] = (MOD - (MOD / i)*inv[MOD % i]%MOD) % MOD;
        invfact[i] = (inv[i]*invfact[i-1]) % MOD;
    }

    return;
}

Int comb(Int n, Int r) {
    if(n < r)
        return 0;

    return (fact[n]*invfact[n-r]%MOD)*invfact[r]%MOD;
}

int main(void) {
    cin>>N>>M>>K;
    init(N*M);

    Int sum = 0;
    for(Int d = 1;d < M;d++) {
        sum += ((((comb(N*M-2,K-2)*d)% MOD)*(M-d)%MOD)*N%MOD)*N%MOD;
    }
    sum %= MOD;

    for(Int d = 1;d < N;d++) {
        sum += ((((comb(N*M-2,K-2)*d)%MOD)*(N-d)%MOD)*M%MOD)*M%MOD;
    }
    sum %= MOD;

    cout<<sum<<endl;

    return 0;
}


