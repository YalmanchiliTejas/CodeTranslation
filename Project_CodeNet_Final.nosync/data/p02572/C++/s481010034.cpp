#include<bits/stdc++.h>
using namespace std;
 
#define ll          long long int
#define ld          long double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define endl        '\n'
#define fd(n)       fixed<<setprecision(n)
#define MAX         100000000000000000
#define MAXN        1000005
#define mod         1000000007  
#define pi          3.1415926535897932384626433
 
ll fun(ll x,ll y){
    ll ans=1;
    while(y>0){
        if(y%2==1){
            ans=ans*1ll*x;
            ans=ans%mod;
        }
        y=y/2;
        x=(x*1ll*x)%mod;
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,y,z;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0,x=0;
    for(i=0;i<n;i++){
        x=x+a[i];
        x=x%mod;
    }
    // cout<<x<<endl;
    for(i=0;i<n;i++){
        y=x*1ll*a[i];
        y=y%mod;
        // cout<<y<<endl;
        ans+=y;
        ans%=mod;
    }
    ll sum1=0;
    for(i=0;i<n;i++){
        sum1+=a[i]*1ll*a[i];
        sum1%=mod;
    }
    ans-=sum1;
    ans+=mod;
    ans%=mod;
    ll p=2;
    ans=ans*1ll*fun(p,mod-2);
    ans=ans%mod;
    cout<<ans<<endl;
}