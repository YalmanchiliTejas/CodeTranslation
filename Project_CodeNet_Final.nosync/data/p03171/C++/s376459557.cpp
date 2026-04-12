#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

ll dp[3009][3009];
ll a[3009];
ll f(ll i,ll j){
    ll &ref = dp[i][j];
    if(ref!=-1)
        return ref;
    ref = 0;
    if(i>j)
        return ref=0;
    
    return ref = max(a[i]-f(i+1,j),a[j]-f(i,j-1));
}
int main(){
    fast;
    ll n;cin>>n;
    
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<max(a[0]-f(1,n-1),a[n-1]-f(0,n-2));
    return 0;
}