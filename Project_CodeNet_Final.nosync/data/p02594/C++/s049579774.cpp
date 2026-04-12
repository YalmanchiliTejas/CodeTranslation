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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
using vvll = vector< vector<ll> >;
using vll = vector<ll> ;
using vb = vector<bool> ;
using pll = pair<ll, ll> ;

const ll maxs = 1e6+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e15;

ll fast(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        y >>= 1;
    }
    return res;
}

ll inv(ll n){
    return fast(n,mod-2);
}


void pre(){


}

void solve(){

    ll n;
    cin  >> n;
    if(n >= 30){
        cout << "Yes";
    }else{
        cout << "No";
    }

}

int main(){
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