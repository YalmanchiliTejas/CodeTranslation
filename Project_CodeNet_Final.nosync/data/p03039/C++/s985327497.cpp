#include<iostream>
using namespace std;
const int mod=1e9+7;

long modpow(long x,long p){
    long res=1;
    while(p){
        if(p&1) res = res*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return res;
}

long C(int n, int r) {
    long mul=1;
    long div=1;
    for(int i=0;i<r;i++){
        mul = mul*(n-i)%mod;
        div = div*(i+1)%mod;
    }
    div = modpow(div,mod-2);
    return mul*div%mod;
}


int main(){
    long n,m,k;
    cin >> n >> m >> k;

    long ans=0;
    for(int i=1;i<m;i++)
        ans=(ans+(m-i)*i%mod*n*n%mod)%mod;

    for(int i=1;i<n;i++)
        ans=(ans+(n-i)*i%mod*m*m%mod)%mod;
    
    ans*=C(n*m-2,k-2);
    ans%=mod;
    cout << ans << endl;
    return 0;
}
