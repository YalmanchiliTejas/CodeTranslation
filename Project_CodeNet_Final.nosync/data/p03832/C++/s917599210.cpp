typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

ll n,a,b,c,d;
ll mod = 1e9+7;
ll dp[1010][1010];

const ll MOD = 1000000007;
const int SIZE = 1010;
ll inv[SIZE],fac[SIZE],finv[SIZE];
void make(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<SIZE;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

ll powmod(ll a, ll n){
    a%=mod;
    if(n==1) return a;
    if(n==0) return 1;
    if(n%2==0){
        return powmod(a,n/2)*powmod(a,n/2) %mod;
    }else{
        return powmod(a,(n-1)/2)%mod*powmod(a,(n-1)/2)%mod*a %mod;
    }
}

int main() {
    std::cin >> n>>a>>b>>c>>d;
    make();
    for (int i = 0; i <= n; i++) {
        dp[i][0]=1;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = a; i <= b; i++) {
            dp[i][j]=dp[i-1][j]%MOD;
            for (int k = c; k <= d && j-k*i >= 0; k++) {
                dp[i][j] += dp[i-1][j - k*i] * fac[n-j+k*i] %MOD * finv[n-j] %MOD * finv[k] %MOD * powmod(finv[i],k) %MOD;
            }
            dp[i][j] %= MOD;
        }
    }
    std::cout << dp[b][n] << std::endl;
}
