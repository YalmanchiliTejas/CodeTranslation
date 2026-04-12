#include<iostream>
#include<vector>
#include<string>
#include<functional>

int main(){
    constexpr long long mod = 1e9+7;
    std::function<long long(long long,long long)>
    mpow = [&](long long a,long long N){
        long long res=1;
        while(N){
            if(N&1) res=res*a%mod;
            a=a*a%mod;
            N>>=1;
        }
        return res;
    };
    std::string s;std::cin>>s;
    int k;std::cin>>k;
    int n=s.size();
    std::vector<long long> fac(n+1,1),ifac(n+1,1);
    for(int i=0;i<n;++i) fac[i+1]=fac[i]*(i+1)%mod;
    ifac[n]=mpow(fac[n],mod-2);
    for(int i=n;i>0;--i) ifac[i-1]=ifac[i]*i%mod;
    std::function<long long(int,int)>
    comb = [&](int N,int r){
        if(N<r||N<0||r<0) return 0LL;
        return fac[N]*ifac[N-r]%mod*ifac[r]%mod;
    };
    long long ans=0;
    int r=0;
    while(k&&n){
        ans+=mpow(9,k)*comb(n-1,k)%mod+(s[r]-'1')*mpow(9,k-1)*comb(n-1,k-1)%mod;
        ans%=mod;
        r++;
        while(r<s.size()&&s[r]=='0'){
            r++;
        }
        k--;n=s.size()-r;
    }
    if(k==0) ans++;
    std::cout<<ans%mod<<std::endl;
}