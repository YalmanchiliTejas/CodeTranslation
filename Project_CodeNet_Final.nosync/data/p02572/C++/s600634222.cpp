#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define I insert
#define endl '\n'
#define all(x) x.begin(), x.end()
#define arr array

template<typename T> void umin(T& a,T b){a = min(a,b);}
template<typename T> void umax(T& a,T b){a = max(a,b);}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
using vvll = vector< vector<ll> >;
using vll = vector<ll> ;
using pll = pair<ll, ll> ;

const ll maxs = 1e6+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e15;


void pre(){

    

}


void solve(){

    ll n;
    cin >> n;
    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    ll suf[n+1];
    suf[n] = a[n];
    for(int i=n-1;i>=1;i--){
        suf[i] = (suf[i+1] + a[i])%mod;
    }
    
    ll ans=0;
    for(int i=1;i<n;i++){
        ans += (a[i]*suf[i+1])%mod;
        ans %= mod;
    }
    cout << ans;
        
}

int32_t main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input00.txt","r",stdin);
    // #endif
    IOS;
    pre();
    ll T = 1;
    //cin>>T;
    while(T--){
        solve();   
    }
    return 0;
}