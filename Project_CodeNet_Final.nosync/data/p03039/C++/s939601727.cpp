#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define N_MAX 200002
ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll inv_(ll n){
    if(n == 1) return 1;
    else return MOD-inv_(MOD%n)*(MOD/n)%MOD;
}

ll comb(ll n, ll r){
  ll ans;
  if(n < r){
      ans = 0;
  }else{
      ans = (fac[n]*finv[r])%MOD;
      ans = (ans*finv[n-r])%MOD;
      ans = (ans+MOD)%MOD;
  }
  return ans;
}

int main(){
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll ans = 0;
    ll N, M, K;
    cin >> N >> M >> K;
    for(ll x = 1; x <= N; x++){
        for(ll y = 1; y <= M; y++){
            ll tmp = (((x*(x-1))/2+((N-x)*(N-x+1))/2)%MOD)*M;
            tmp %= MOD;
            tmp += (((y*(y-1))/2+((M-y)*(M-y+1))/2)%MOD)*N;
            tmp %= MOD;
            ans += tmp;
            ans %= MOD;
        }
    }
    //cout << ans << endl;
    ans *= inv[N*M];
    ans %= MOD;
    ans *= inv[N*M-1];
    ans %= MOD;
    ans *= comb(N*M, K);
    ans %= MOD;
    ans *= comb(K, 2);
    ans %= MOD;
    cout << ans << endl;
}