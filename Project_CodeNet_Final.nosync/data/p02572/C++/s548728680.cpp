#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<functional>
using namespace std;
#define ll long long int
#define ld long double
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,
tree_order_statistics_node_update> in_set;
#define rep(n) for(ll i=0;i<(n);i++)
#define jrep(n) for(ll j=0;j<(n);j++)
#define krep(n) for(ll k=0;k<(n);k++)
#define all(a) (a).begin(), (a).end()
#define dpp(a) cout<<(a).first<<" "<<(a).second<<endl;
#define append push_back
#define mod 1000000007
#define ff first
#define ss second
#define ffast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fast ios::sync_with_stdio(0);
ll pw(ll x,ll y,ll p=mod){ll r=1; x=x%p;while(y>0){ if(y&1)r=(r*x)%p;
y=y>>1;x=(x*x)%p;} return r; } 

void solve(ll ts){
    ll n; cin>>n; vector<ll> arr(n); rep(n) cin>>arr[i];
    ll su=accumulate(all(arr),(ll)0);
    su%=mod;
    ll prod = (su*su)%mod;
    for(auto i:arr) prod=(prod+mod-(i*i)%mod)%mod;
    cout<<(prod*pw(2,mod-2,mod))%mod<<endl;
} 
int main(){
    ffast
    ll t=1;
//    cin>>t;
    rep(t) solve(i+1);
}
 
 
// *p.find_by_order(n) : nth value (0 indexed)
// p.order_of_key(7): index of 7 (0 indexed)
