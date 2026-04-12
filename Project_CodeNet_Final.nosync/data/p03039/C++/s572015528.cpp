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
#define MAX_MN (200000+10)

using namespace std;

typedef long long int Int;

Int fact[MAX_MN];
Int inv[MAX_MN];
Int invfact[MAX_MN];

Int comb(Int n,Int k) {
    if(!(k >= 0 && k <= n))
        return 0;

    return (((fact[n]*invfact[n-k])%MOD)*invfact[k])%MOD;
}

Int solve(Int n,Int m,Int k) {
    Int patterns = comb(n*m-2,k-2);
    Int sum = 0;
    
    for(Int d = 0;d <n;d++) {
        Int ans = ((d*(n-d)%MOD)*m%MOD)*m%MOD;
        sum = (sum + ans) % MOD;
    }
    for(Int d = 0;d < m;d++) {
        Int ans = ((d*(m-d)%MOD)*n%MOD)*n%MOD;
        sum = (sum + ans) %MOD;
    }
    
    return sum * patterns % MOD;
}

int main(void) {
    Int n,m,k;
    cin>>n>>m>>k;
    
    fact[0] = 1;
    inv[1] = 1;
    invfact[0] = 1;
    
    for(Int i = 2;i <= n*m+1;i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD%i] % MOD;
    }
    for(Int i = 1;i <= n*m+1;i++) {
        fact[i] = (fact[i-1]*i) % MOD;
        invfact[i] = (invfact[i-1]*inv[i])%MOD;
    }

    cout<<solve(n,m,k)<<endl;

    return 0;
}


