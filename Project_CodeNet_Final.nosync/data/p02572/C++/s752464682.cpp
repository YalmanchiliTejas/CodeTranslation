#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll M=1e9+7;

int main(){
    ll n;
    cin>>n;
    ll a[n+1],pre[n+1]={0},ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=(pre[i-1]+a[i])%M;
    }
    //cout<<pre[n+1]<<"\n";
    for(int i=1;i<n;i++){
        ll sub=(pre[n]-pre[i]+M)%M;
        //cout<<a[i]<<" "<<sub<<"\n";
        ll temp=(a[i]*sub)%M;
        ans=(ans+temp+M)%M;
    }
    cout<<ans<<"\n";
    
    return 0;
}
