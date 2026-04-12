#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define ff first
#define ss second
#define dd double
#define mod 1000000007

template<class K,class other=null_type,class cmp=less<K>> using ordered_set=tree<K,other,
cmp, rb_tree_tag, tree_order_statistics_node_update>;

inline ll md(ll x){
    return x<mod?x:x%mod;
}

ll power(ll x, ll y){
    if(y==0){
        return 1;
    }
    ll x_=power(x,y/2);
    if(y & 1){
        return md(md(x_*x_)*md(x));
    }
    else{
        return md(x_*x_);
    }
}

ll mod_inverse(ll x){
    return power(x,mod-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    ll pref[n];
    ll suff[n];
    REP(i,n){
        cin>>arr[i];
    }
    pref[0]=arr[0];
    FOR(i,1,n){
        pref[i]=(pref[i-1]+arr[i])%mod;
    }
    suff[n-1]=arr[n-1];
    for(ll i=n-2;i>=0;i--){
        suff[i]=(suff[i+1]+arr[i])%mod;
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(i==0){
            ll temp=suff[i+1];
            ans=(ans+(arr[i]*temp)%mod)%mod;
        }
        else if(i==n-1){
            ll temp=pref[i-1];
            ans=(ans+(arr[i]*temp)%mod)%mod;
        }
        else{
            ll temp=suff[i+1];
            ans=(ans+(arr[i]*temp)%mod)%mod;
            temp=pref[i-1];
            ans=(ans+(arr[i]*temp)%mod)%mod;
        }
    }
    cout<<(ans*mod_inverse(2))%mod<<endl;
}
