#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ld  double
#define ff first
#define ss second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
ll mod =   1e9 +7  ;
//const ll inf  = 1e9 + 10 ;
ll multiply(ll a, ll b ){ return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b) {     return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) { return ((a%mod) - (b % mod)+ mod) % mod ; }
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
void solve(){
    ll x ;
    cin >> x ;
    if(x>=30){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1 ;
   // cin >> t ;
    while(t--){
        solve( );
    }
}

