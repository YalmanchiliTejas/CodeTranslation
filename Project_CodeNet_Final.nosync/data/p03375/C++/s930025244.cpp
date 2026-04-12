#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define N_MAX 3005

using namespace std;
typedef long long ll;
int N;
ll M, MOD;
ll pow2[10000000];
ll powpow2[3005];
ll dp[3005][3005];
ll inv[N_MAX],fac[N_MAX],finv[N_MAX];

void init(){
    pow2[0] = 1;
    powpow2[0] = 2;
    for(int i = 1; i < 10000000; i++){
        pow2[i] = pow2[i-1]*2;
        pow2[i] %=M;
    }
    for(int i = 1; i <= 3004; i++){
        powpow2[i] = powpow2[i-1]*powpow2[i-1];
        powpow2[i] %= M;
    }
    for(int i = 1; i <= 3004; i++){
        dp[i][1] = 1;
        dp[i][i] = 1;
        for(int j = 2; j < i; j++){
            dp[i][j] = dp[i-1][j]*j+dp[i-1][j-1];
            dp[i][j] %= M;
        }
    }
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

template <typename T>
T pow(T a, ll n){
    T ans = 1;
    T tmp = a;
    for(int i = 0; i <= 60; i++){
        ll m = (ll)1 << i;
        if(m&n){
            ans *= tmp;
            ans %= M;
        }
        tmp *= tmp;
        tmp %= M;
    }
    return ans;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N >> M;
    MOD = M;
    init();
    ll ans = powpow2[N];
    // cout  << ans << endl;
    for(int i = 1; i <= N; i++){
        ll tmp = 0;
        for(int j = 0; j <= i; j++){
            tmp += dp[i+1][j+1]*pow2[(N-i)*j];
            tmp %= M;
        }
        tmp *= powpow2[N-i];
        tmp %= M;
        tmp *= comb(N, i);
        tmp %= M;
        ans += (i%2 == 0 ? tmp:-tmp);
        ans %= M;
        ans += M;
        ans %= M;
        // cout << tmp << endl;
    }
    cout << ans << endl;
}