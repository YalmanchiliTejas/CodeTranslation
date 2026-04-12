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

Int N,M,K;
Int inv[200000+10];
Int fact[200000+10];
Int invfact[200000+10];

Int comb(Int n,Int r) {
    if(r > n)
        return 0;
    if(n == 0 || r == 0)
        return 1;

    return ((fact[n] * invfact[n-r] % MOD) * invfact[r]) % MOD;
}

void solve(void) {
    fact[0] = fact[1] = 1;
    inv[1] = 1;
    invfact[0] = invfact[1] = 1;

    for(Int i = 2;i <= 200000+5;i++) {
        fact[i] = fact[i-1]*i % MOD;
        inv[i] = MOD - (MOD / i)*inv[MOD % i] % MOD;
        invfact[i] = inv[i]  * invfact[i-1] % MOD;
    }

    Int sum = 0;
    for(Int i = 1;i <= N;i++) {
        sum = (sum + comb(N*M-2,K-2)*i*(N-i)*M*M) % MOD;
    }
    for(Int i = 1;i <= M;i++) {
        sum = (sum + comb(N*M-2,K-2)*i*(M-i)*N*N) % MOD;
    }

    cout<<sum<<endl;

    return;
}
int main(void) {
    cin>>N>>M>>K;

    solve();

    return 0;
}


