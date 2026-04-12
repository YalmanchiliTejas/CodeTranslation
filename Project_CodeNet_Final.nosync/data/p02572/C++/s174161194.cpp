#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll mod=1e9+7;

ll powpow(ll a, ll n){
    ll ret=1;
    while(n>0){
        if(n&1) ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;    
}

ll invmod(ll a){
    return powpow(a,mod-2);
}

int main(){

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<ll> a2(n);
    for(int i=0;i<n;i++){
        a2[i]=a[i]*a[i]%mod;
    }
    ll ans=0;
    ll sum=0;
    ll sum2=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        sum%=mod;
        sum2+=a2[i];
        sum2%mod;
    }
    //cout << sum << " " << sum2 << endl;
    ans+=((sum*sum)%mod-sum2+mod)%mod;
    ans=(ans*invmod(2)+mod)%mod;
    ans=(ans+mod)%mod;
    cout << ans << endl;
   
    return 0;
}