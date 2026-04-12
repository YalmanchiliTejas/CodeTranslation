#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
 
int main(){
    ll n,sum=0,summ=0,a[200005];
    cin>>n;
    rep(i,n){
        cin>>a[i];
        sum+=(a[i])%mod;
      sum%=mod;
        summ+=((a[i]%mod)*(a[i]%mod))%mod;
      summ%=mod;
    }
    cout<<(((sum*sum+mod-summ)%mod)*((mod+1)/2))%mod;
}