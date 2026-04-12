#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a;
    cin>>a;
    ll arr[a],sum[a],su=0;
    for(ll i=0;i<a;i++){
        cin>>arr[i];
        sum[i]=su%1000000007;
        su=(su%1000000007)+(arr[i]%1000000007);
    }
    ll ans=0;
    for(int i=a-1;i>-1;i--){
        ans+=((arr[i]%1000000007)*(sum[i]%1000000007))%1000000007;
    }
    ans=ans%1000000007;
    cout<<ans;
}
int main(){
    ll bb=1;
    //cin>>a;
    while(bb--){
        solve();
    }
}