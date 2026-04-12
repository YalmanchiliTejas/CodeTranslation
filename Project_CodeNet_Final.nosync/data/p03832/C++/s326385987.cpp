#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
const lint mod = 1e9 + 7;

int n, a, b, c, d;
lint dp[1010][1010];

lint powmod(long x, long n){
  lint ret = 1;
  while(n > 0){
    if(n&1) ret *= x, ret %= mod, n -= 1;
    else x *= x, x %= mod, n >>= 1;
  }
  return ret;
}

vector<lint> fact;
vector<lint> revfact;

void setfact(int n){
  fact.resize(n+1); revfact.resize(n+1);
  fact[0] = 1;
  rep(i, n) fact[i+1] = fact[i] * (i+1) % mod;
  
  revfact[n] = powmod(fact[n], mod-2);
  for(int i=n-1; i>=0; i--) revfact[i] = revfact[i+1] * (i+1) % mod;
}

lint f(int i, int j, int k){
    return fact[n-(j-i*k)] * revfact[k] % mod * revfact[n-(j-i*k)-i*k] % mod * powmod(revfact[i], k) % mod;
}

lint dfs(int i, int j){
    if(dp[i][j] >= 0) return dp[i][j];
    lint ret = dfs(i-1, j) * f(i, j, 0) % mod;
    For(k, c, d+1){
        if(j < i*k) break;
        if(i == a && j > i*k) continue;
        ret = (ret + dfs(i-1, j-i*k) * f(i, j, k) % mod) % mod;
    }
    return dp[i][j] = ret;
}

int main(){
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    setfact(2000);
    rep(i, b+1)rep(j, n+1) dp[i][j] = -1;
    rep(j, n+1){
        if(j%a || (1<=j && j<a*c) || j>a*d) dp[a][j] = 0;
        else{
            int k = j / a;
            dp[a][j] = fact[n] * revfact[n-j] % mod * revfact[k] % mod * powmod(revfact[a], k) % mod;
        }
    }
    printf("%lld\n", dfs(b, n));
}