#include <bits/stdc++.h>
#define ll long long
const ll m=1e9+7;
using namespace std;
ll add(ll i,ll j){
    return ((i%m)+(j%m))%m;
}
ll mod(ll i,ll j){
    return ((i%m)*(j%m))%m;
}
int main(){
    int n;
    cin>>n;
    vector<ll>v(n+1,0);
    vector<ll>presum(n+1,0);
    v[n]=0;
    presum[n]=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]=v[i]%m;
    }
    for(int i=n-1;i>=0;i--){
        presum[i]=add(presum[i+1],v[i+1]);  
    }
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        ans+=mod(presum[i],v[i]);
        ans%=m;
    }
    cout<<ans<<endl;
}