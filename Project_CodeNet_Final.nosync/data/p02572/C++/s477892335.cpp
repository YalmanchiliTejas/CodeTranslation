#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ll mod=1e9+7;
    int n;cin>>n;
    vector <ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll presum=0;
    for(int i=0;i<n;i++){
        presum=(presum%mod+v[i]%mod)%mod;
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        presum=(presum%mod-v[i]%mod+mod)%mod;
        sum=(sum%mod+(v[i]*(presum%mod))%mod)%mod;
    }
        
    cout<<sum<<endl;
}