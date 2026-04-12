#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
 
 
const int MAX = 1000005;
const ll MOD = 1000000007;
 
ll fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
int main(){
    int N, M, K; cin >> N >> M >> K;
    COMinit();
    ll cost = 0;
    REP(i,N)REP(j,M){
        cost += M*((ll)(i+1)*i/2+(ll)(N-i)*(N-i-1)/2) + N*((ll)(j+1)*j/2+(ll)(M-j)*(M-j-1)/2);
        cost %= MOD;
    }
    cost = (cost*500000004)%MOD;
    cost =(COM(N*M-2,K-2)*cost) %MOD;
    cout << cost << endl;
    return 0;
}