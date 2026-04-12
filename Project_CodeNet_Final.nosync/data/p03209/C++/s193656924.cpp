#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll layer[64];
ll patty[64];
void calclayer(){
    layer[0]=1;
    patty[0]=1;
    for(int i=0;i<55;i++){
        layer[i+1]=layer[i]*2+3;
        patty[i+1]=patty[i]*2+1;
    }
}
ll calc(ll n,ll x){
    if(x==0) return 0;
    if(x>0&&x<(layer[n]+1)/2) return calc(n-1,x-1);
    if(x==(layer[n]+1)/2) return patty[n-1]+1;
    if(x>(layer[n]+1)/2&&x<layer[n]) return patty[n-1]+1+calc(n-1,x-(layer[n-1]+2));
    if(x==layer[n]) return patty[n];
    return 0;
}
int main(){
    ll n,x;cin>>n>>x;
    calclayer();
    ll ans=calc(n,x);
    cout<<ans<<endl;
}
