#include <cstdio>


using ll=long long int;

const int MAXN=2e5+3;
const ll MOD=1e9+7;

int N;
ll A[MAXN]
;
ll power(ll base,int exp){
    if (exp==0) return 1ll;
    auto temp=power(base,exp/2);
    return exp%2?temp*temp%MOD*base%MOD:temp*temp%MOD;
}


int main(){
    ll ans=0ll;
    scanf("%d",&N);
    ll sum=0;
    for(int i=0;i<N;i++){
        scanf("%lld",A+i);
        sum=(sum+A[i])%MOD;
    }

    for(int i=0;i<N;i++){
        ans=(ans+A[i]*((sum+(MOD-A[i]))%MOD)%MOD)%MOD;
    }

    printf("%lld\n",ans*power(2,MOD-2)%MOD);
    return 0;
}