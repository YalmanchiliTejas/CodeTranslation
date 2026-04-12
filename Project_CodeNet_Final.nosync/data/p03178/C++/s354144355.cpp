#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
const lint MOD =1000000007;
const lint MAX = 1000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
 
 
lint fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() 
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;
 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
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
    lint lcm(lint a,lint b){
        return a/__gcd(a,b)*b;
    }
     lint gcd(lint a,lint b){
        return __gcd(a,b);
    } 
    lint dp[100005][105][2];
  int main(){
      string s;
      lint d;
      cin>>s>>d;
      dp[0][0][0]=1;
    rep(i,s.size()){
        rep(j,d){
            rep(k,2){
                lint x=s[i]-'0';
                rep(l,10){
                    if(l<x){
                        dp[i+1][(j+l)%d][1]+=dp[i][j][k];
                        dp[i+1][(j+l)%d][1]%=MOD;
                    }else if(l==x){
                         dp[i+1][(j+l)%d][k]+=dp[i][j][k];
                         dp[i+1][(j+l)%d][k]%=MOD;
                    }else{
                      if(k){  dp[i+1][(j+l)%d][k]+=dp[i][j][k];
                         dp[i+1][(j+l)%d][k]%=MOD;}
                    }
                }
            }
        }
    }
    cout<<(dp[s.size()][0][0]+dp[s.size()][0][1]-1+MOD)%MOD;
  }
  
     
