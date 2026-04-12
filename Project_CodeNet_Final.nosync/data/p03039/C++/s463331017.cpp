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

const int max_nm = 200000+19;

Int N,M,K;
Int inv[max_nm];
Int invfact[max_nm];
Int fact[max_nm];

Int comb(Int n, Int r) {
    if(n < 0 || n < r)
        return 0;

    return ((fact[n]*invfact[n-r]%MOD)*invfact[r])%MOD;
}

int main(void) {
    cin>>N>>M>>K;

    fact[0] = fact[1] = 1;
    inv[1] = 1;
    invfact[0] = invfact[1] = 1;
    
    for(Int i = 2;i <= N*M;i++) {
        fact[i] = i*fact[i-1]%MOD;
        inv[i] = MOD - (MOD/i)*inv[MOD%i] % MOD;
        invfact[i] = inv[i]*invfact[i-1] % MOD;
    }

    Int ans = 0;
    
    for(Int d = 1;d < M;d++) {
        ans += (((N*N%MOD)*(M-d)%MOD)*d%MOD)*comb(N*M-2,K-2)%MOD;
        ans %= MOD;
    }

    for(Int d = 1;d < N;d++) {
        ans += (((M*M%MOD)*(N-d)%MOD)*d%MOD)*comb(N*M-2,K-2)%MOD;
        ans %= MOD;
    }

    cout<<ans<<endl;

    return 0;
}
