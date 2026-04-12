#include<cstdio>
long long mod = -1;
long long f[3005], invf[3005];
long long d[3005][3005];
long long count[3005];
long long superPow[3005]; //sp[i] = 2^(2^(i))
long long pow2[9000005];

long long power(long long a,long long b){
    long long res  = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b /= 2;
    }
    return res;
}

long long inv(long long u){ return power(u,mod-2); }

long long getComb(int n,int m){
    if(m>n || m<0) return 0;
    else return f[n]*invf[m]%mod*invf[n-m]%mod;
}

void preWork(int n){
    f[0] = invf[0] = 1;
    superPow[0] = 2;
    for(long long i = 1; i <= n; i++){
        f[i] = i*f[i-1]%mod;
        invf[i] = inv(f[i]);
        superPow[i] = superPow[i-1]*superPow[i-1]%mod;
    }
    pow2[0] = 1;
    for(int i = 1; i <= n*n; i++) pow2[i] = pow2[i-1]*2%mod;
}

void dp(int n){
    d[0][0] = 1;
    for(long long i = 1; i <= n; i++){
        for(long long j = 0; j <= n; j++){
            d[i][j] = d[i-1][j];
            d[i][j] += j*d[i-1][j]%mod; if(d[i][j]>=mod) d[i][j] -= mod;
            if(j!=0) d[i][j] += d[i-1][j-1]; 
            if(d[i][j]>=mod) d[i][j] -= mod;
        }
    }
    for(int i = 0; i <= n; i++){
        count[i] = 0;
        for(int j = 0; j <= i; j++){
            long long add = d[i][j]*pow2[(n-i)*j]%mod;
            count[i] += add; if(count[i]>=mod) count[i] -= mod;
        }
        count[i] = count[i]*superPow[n-i]%mod;
    }
}


int main(){
    int n;
    scanf("%d%lld",&n,&mod);
    preWork(n), dp(n);
    long long ans = 0, sign = mod-1;
    for(int i = 0; i <= n; i++){
        long long cur = getComb(n,i)*count[i]%mod;
        if(i%2) cur = cur*sign%mod;
        ans = (ans+cur)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
