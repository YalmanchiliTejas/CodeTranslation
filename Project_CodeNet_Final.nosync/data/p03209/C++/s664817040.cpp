#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=1000000000000000;
typedef pair<ll,ll> l_l;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back


ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

ll hoge(ll i,ll j){
    if(i==0){
        return 1;
    }
    if(j==1){
        return 0;
    }
    if(j==pow(2,i+1)-1){
        return pow(2,i);
    }
    if(j==pow(2,i+2)-3){
        return pow(2,i+1)-1;
    }
    if(j<pow(2,i+1)-1){
        return hoge(i-1,j-1);
    }
    return pow(2,i)+hoge(i-1,j-(pow(2,i+1)-1));
    
}

int main(){
    ll n,x;cin>>n>>x;
    ll ans=hoge(n,x);
    cout<<ans<<endl;
    
    
    return 0;
}


