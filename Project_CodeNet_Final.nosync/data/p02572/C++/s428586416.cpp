#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;;
#define ato find_by_order
#define of order_of_key
typedef long long ll;
#define pb push_back
#define flash ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
ll val[100005];ll ans[100005];vector<ll> graph[100005];
ll vis[100005]; ll weight[100005];
void dfs(ll curr,ll c,ll kabad) {
    
    vis[curr]=1;
    if(val[curr]==1){
        c++;
        kabad=max(kabad,c);
        ans[curr]=kabad;
    }
    else {
        c=0;
        ans[curr]=kabad;
    }
    for(auto x:graph[curr]) {
        ll child=x;
        if(vis[child]==0){
            
            dfs(child,c,kabad);
        }
    }
}
ll mul(ll a,ll b,ll m){
    ll res=((a%m)*(b%m))%m;
    return res;
}

int main(){
    ll t;
    t=1;
    while(t--) {
        ll n;
        cin >> n;
        ll a[n+1]={0};
        ll suff[n+1]={0};
        for(ll i=1;i<=n;i++){
            cin >> a[i];
        }
        suff[n]=a[n];
        for(ll i=n-1;i>=2;i--){
            suff[i]=a[i]+suff[i+1];
        }
        ll ans=0,m=1e9+7;
        for(ll i=1;i<n;i++){
            ans+=(mul(a[i],suff[i+1],m));
            ans=ans%m;
        }
        ans=ans%m;
        cout<<ans<<endl;
        
        
        
    }
}
