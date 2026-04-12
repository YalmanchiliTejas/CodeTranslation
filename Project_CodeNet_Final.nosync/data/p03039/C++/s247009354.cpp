#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

#define MAX 200010
ll fac[MAX];
ll finv[MAX];
ll inv[MAX];

void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    repr(i,2,MAX){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll COM(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}


int main(){
    COMinit();
    ll N,M,K; cin >> N >> M >> K;
    ll ans = 0;
    repr(i,1,N){
        ans += i*(N-i)*M%MOD*M%MOD;
        ans %= MOD;
    }
    repr(i,1,M){
        ans += i*(M-i)*N%MOD*N%MOD;
        ans %= MOD;
    }
    ans *= COM(N*M-2,K-2);
    ans %= MOD;
    cout << ans << endl;
}
