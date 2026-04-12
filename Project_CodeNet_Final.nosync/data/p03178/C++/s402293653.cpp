#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string k;
ll n,d;
const ll mod=1e9+7;
ll memo[100001][2][101];
ll go(ll pos,ll par,ll val){
    if(pos==n){
        if(val%d==0) return 1;
        return 0;
    }
    if(memo[pos][par][val]!=-1) return memo[pos][par][val];
    ll ans=0;
    if(par==0){
        for(ll i=0;i<10;i++){
            ans+=go(pos+1,par,(val+i)%d);
            ans%=mod;
        }
    }
    else{
        ans+=go(pos+1,par,(val+k[pos]-'0'+d)%d);
        ans%=mod;
        for(ll i=0;i<k[pos]-'0';i++){
            ans+=go(pos+1,0,(val+i)%d);
            ans%=mod;
        }
    }
    return memo[pos][par][val]=ans;
}

int main(){

    cin>>k>>d;
    memset(memo,-1,sizeof(memo));
    n=k.size();
    ll ans=(go(0,1,0)-1+mod)%mod;
    cout<<ans;

}