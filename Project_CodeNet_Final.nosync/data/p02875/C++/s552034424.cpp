#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int fact[11000000];
Int revfact[11000000];
Int rev[11000000];

void init(){
    Int m = MOD;
    fact[0] = 1;
    revfact[0] = 1;
    rev[0] = 0;
    rev[1] = 1;
    for(int i = 1;i < 11000000;i++){
        fact[i] = fact[i-1] * i % m;
        if(i>1)rev[i] = MOD / i * (MOD-rev[MOD % i]) % MOD;
        revfact[i] = revfact[i-1] * rev[i] % MOD;
    }
}

Int nCk(Int n, Int k){
    if(n < k)return 0;
    return fact[n] * revfact[n-k] % MOD * revfact[k] % MOD;
}

Int ans;
Int n;
int main(){
    init();
    cin >> n;
    n /= 2;
    Int tmp = nCk(2*n, n);
    Int pow2 = 1;
    for(Int i = 0;i < n;i++){
//        cout << ans << " " << tmp << endl;
        ans += nCk(2*n, i) * tmp % MOD;ans %= MOD;
        tmp += nCk(2*n-i-1,n);
        tmp += nCk(2*n-i-1,n-i-1);
        tmp %= MOD;
        tmp *= rev[2];
        tmp %= MOD;
        ans += pow2 * nCk(2*n, 2*n-i);
        pow2 *= 2;
        pow2 %= MOD;
    }
    ans += nCk(2*n, n) * pow2 % MOD;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}