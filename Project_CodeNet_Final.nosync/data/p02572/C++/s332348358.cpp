#include <bits/stdc++.h>
#define mod 1000000007
#define ll unsigned long long
using namespace std;
ll po(ll a,ll n){
    ll res=1;
    a%=mod;
    while(n){
        if(n&1)res=(res*a)%mod;
        n>>=1;
        a=(a*a)%mod;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    unsigned long long a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    unsigned long long su=0,su1=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            continue;
        }
        su+=a[i];
        su%=mod;
        a[i]*=a[i];
        a[i]%=mod;
        su1+=a[i];
        su1%=mod;
    }
    su=((su%mod)*(su%mod))%mod;
    su=((su-su1+mod)*((po(2,mod-2))%mod))%mod;
    cout<<su;
    
}