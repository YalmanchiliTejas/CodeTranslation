#include <iostream>
#define mod (long long)(1e9+7)
using namespace std;
int main(void){
    
    long long a,b,x;
    scanf("%lld%lld%lld",&a,&b,&x);
    if(x<a)printf("%lld\n",x%mod);
    else{
        long long syo;
        syo=(x-b)/(a-b);
        long long ans=0;
        ans+=(syo%mod)*(a%mod)%mod;
        ans%=mod;
        ans+=(x-(syo%mod)*((a-b)%mod))%mod;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}

