#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5+10;
const int mod = 1e9+7;
LL fac[maxn],inv[maxn];
LL qpow(LL a,int n){LL ans = 1; for (;n;n>>=1, a = a * a % mod) if (n & 1) ans = ans * a % mod; return ans;}
void init(){
    fac[0] = 1;
    for (int i=1;i<maxn;i++) fac[i] = fac[i-1] * i % mod;
    inv[maxn-1] = qpow(fac[maxn-1], mod-2);
    for (int i=maxn-2;i>=0;i--) inv[i] = inv[i+1] * (i+1) % mod;
}
void up(LL &x,LL y){
    x += y;
    if (x >= mod) x -= mod;
}
LL C(int n, int m){
    return fac[n] * inv[m] % mod * inv[n-m] % mod;
}
int main(){
    init();
    int n,m,k;
    cin>>n>>m>>k;
    LL sumn = 0, summ = 0;
    for (int i=2;i<=n;i++) up(sumn , 1LL * (i-1) * (n-i+1) % mod);
    for (int j=2;j<=m;j++) up(summ , 1LL * (j-1) * (m-j+1) % mod);

//    cout<<sumn<<" "<<summ<<endl;
    sumn = sumn * m % mod * m % mod;
    summ = summ * n % mod * n % mod;
//    cout<<sumn<<"\t"<<summ<<endl;

    LL p = C(n*m-2, k-2);
//    cout<<"p = "<<p<<endl;
    LL ans = (sumn + summ) % mod * p % mod;
    cout<<ans<<endl;
    return 0;
}
