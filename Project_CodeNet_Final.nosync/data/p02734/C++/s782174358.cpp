#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(lint (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
#define all(x) (x).begin(),(x).end()
const lint MOD =1000000007;
const lint MAX = 1000000;
using Graph =vector<vector<lint>>;
typedef pair<lint,lint> P;
typedef map<lint,lint> M;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
 
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
    lint dp[3100][3100][3];
    int main(){
    lint n,s;
    cin>>n>>s;
    lint a[n];
    rep(i,n)cin>>a[i];
    dp[0][0][0]=1;
    lint mod=998244353;
    rep(i,n){
        rep(j,s+1){
            dp[i+1][j][0]+=dp[i][j][0];
            dp[i+1][j][1]+=dp[i][j][1];
            dp[i+1][j][2]+=dp[i][j][2];
            if(j-a[i]>=0){
                dp[i+1][j][1]+=dp[i][j-a[i]][1];
                dp[i+1][j][1]+=dp[i][j-a[i]][0]*(i+1);
                dp[i+1][j][2]+=dp[i][j-a[i]][0]*(i+1)*(n-i);
                 dp[i+1][j][2]%=mod;
                dp[i+1][j][2]+=dp[i][j-a[i]][1]*(n-i);
            }
            dp[i+1][j][0]%=mod;
            dp[i+1][j][1]%=mod;
            dp[i+1][j][2]%=mod;

        }
    }
    cout<<dp[n][s][2]<<endl;
    }
      