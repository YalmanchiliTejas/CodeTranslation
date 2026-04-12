#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
vector<int> dy = {0,0,1,-1};
vector<int> dx = {1,-1,0,0};

//コンビネーション
const int MAXcomb = 200010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAXcomb; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}

ll N, M, K;
int main(void){
    COMinit();
    cin >> N >> M >> K;
    ll ans = 0;
    
    for(int d = 0; d <= M - 1; d++){
        ans += (M - d) % MOD * N % MOD * N % MOD * d % MOD;
        ans %= MOD;
    }
    
    for(int d = 0; d <= N - 1; d++){
        ans += (N - d) % MOD * M % MOD * M % MOD * d % MOD;
        ans %= MOD;
    }
    ans *= comb(N * M - 2, K - 2);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << endl;
}
