/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*/
#include<bits/stdc++.h>
using namespace std;
 
// General
#define ll long long
#define ld long double
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007 // 998244353
#define PI 3.1415926535897932384
#define endl "\n"
#define debug(x) cout<<x<<endl
#define REP(i,n) for(i=0;i<n;++i)
#define FOR(i,x,n) for(i=x;i<n;++i)
#define RREP(i,n) for(i=n-1;i>=0;--i)
#define RFOR(i,x,n) for(i=n-1;i>=x;--i)
#define TR(i,c) for(auto i=c.begin();i!=c.end();++i)
#define RTR(i,c) for(auto i=c.rbegin();i!=c.rend();++i)
#define sz(a) a.size()
 
// Bounds
#define lb(a,x) a.lower_bound(x)
#define ub(a,x) a.upper_bound(x)
#define all(a) a.begin(),a.end()
 
// Vector
#define vi vector <int>
#define pb(v,x) v.push_back(x)
#define vll vector <ll>
 
// Map
#define mii map <int, int>
#define umii unordered_map <int, int>
 
// Set
#define si set <int>
#define msi multiset<int>
 
// Pair
#define vpii vector<pair < int, int > >
#define vpll vector<pair < ll, ll > >
#define pii pair < int, int >
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define vppi vector<pair<pair<int,int>,int>>
#define ppi pair<pair<int,int>,int>

void solve();

int main(){
    io
    ll t;
    t=1;
    // cin >> t;
    for(int i=0;i<t;++i) solve();
    return 0;
}

void solve() {
    ll i, j, n;
    cin >> n;
    vi a(n);
    REP(i,n) cin >> a[i];
    ll ans = 0, sum = a[0] % mod;
    // cout << "sum=" << sum << endl;
    FOR(i,1,n) {
        ll temp = ((sum%mod) * (a[i]%mod)) % mod;
        ans = ((ans%mod) + ((temp)%mod)) % mod;
        sum = ((sum % mod) + (a[i]%mod)) % mod;
        // cout << "sum=" << sum << endl;
    }
    cout << ans << endl;
}
