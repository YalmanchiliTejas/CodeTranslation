#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+7;
ll LLpow(ll a, ll b){
    if(b==0) return 1;
    else{
        if(b&1){
            return a*LLpow(a,b-1)%mod;
        }else{
            ll mul=LLpow(a,b/2)%mod;
            return mul*mul%mod;
        }
    }
}

ll prefix[200010]={0},ori[200010]={0};

int main(){
    ll n,sum=0,res=0;
    scanf("%lld",&n);
    for(ll i=0;i<n;i++){
        ll s;
        scanf("%lld",&s);
        ori[i]=s;
        sum+=s;
        sum%=mod;
        prefix[i]=sum;
        //sum=((sum%mod)*(LLpow(s,i+1)%mod))%mod;
    }
    for(ll i=0;i<n;i++){
        res=(res+((ori[i]%mod)*(prefix[n-1]-prefix[i]+mod)%mod))%mod;
        res%=mod;
    }
    printf("%lld",res);
    return 0;
}
