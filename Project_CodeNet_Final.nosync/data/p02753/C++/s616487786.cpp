// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int int
#define ll int
#define bits_count __builtin_popcountll
#define endl '\n'
#define double double
#define ld double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define FI(i,n) for (ll i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
    string s; cin>>s;

    int a = 0,b = 0;
    if(s[0] == 'A') a++; else b++;
    if(s[1] == 'A') a++; else b++;
    if(s[2] == 'A') a++; else b++;
    
    if(a == 0 || b == 0) cout<<"No\n";
    else cout<<"Yes\n";
}

signed main(){

   FastRead;    

    int t = 1; 
    // cin>>t; 
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}