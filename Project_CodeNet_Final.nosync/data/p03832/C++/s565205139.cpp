#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <utility>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
using P = pair<int,int>;
using ll = long long;
constexpr int MOD=1000000007;
constexpr int MAX=510000;
long long fac[MAX], finv[MAX], inv[MAX];
bool COMinited = false;
long long COM(int n, int k) {
  if (COMinited == false) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      finv[i] = finv[i - 1] * inv[i] % MOD;
    }
    COMinited = true;
  }
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
long long modinv(long long a, long long mod) { return modpow(a, mod - 2, mod); }
int n,a,b,c,d;
vector<vector<int>> dp(1000+1,vector<int>(1000+2,-1));
ll solve(int s,int t){
    if(dp[s][t]!=-1)return dp[s][t];
    ll ret=0;
    ret+=solve(s,t+1);
    for(int i=c;i<=d;i++){
        if(s<t*i)break;           
        ret+=COM(s,t*i)*fac[t*i]%MOD*modinv(modpow(fac[t],i,MOD),MOD)%MOD*modinv(fac[i],MOD)%MOD*solve(s-t*i,t+1)%MOD;
        ret%=MOD;
    }
    dp[s][t]=ret;
    return ret;
}
int main(){
    cin>>n>>a>>b>>c>>d;
    for(int i=a;i<=b+1;i++)dp[0][i]=1;
    for(int i=1;i<=n;i++){
        dp[i][b+1]=0;
    }
    cout<<solve(n,a)<<endl;
}
