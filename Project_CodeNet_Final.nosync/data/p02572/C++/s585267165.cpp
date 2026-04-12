#include <cstdio>
#define ll long long int

#define md 1000000007

ll ppow(ll b, int p){
    ll ret=1;
    for(;p;p/=2){
        if(p&1) ret=(ret*b)%md;
        b=(b*b)%md;
    }
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    
    ll sm=0;
    ll sms=0;
    ll val;
    for(int i=0;i<n;i++){
        scanf("%lld",&val);
        sm+=val;
        sms=(sms+val*val)%md;
    }

    sm%=md;
    ll ans=(sm*sm-sms)%md;
    ans=(ans*ppow(2,md-2))%md;
    if(ans<0) ans+=md;

    printf("%lld\n",ans);
}
