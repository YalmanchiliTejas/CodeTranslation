    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    using namespace std;
    using namespace __gnu_pbds;
    #define endl "\n"
    #define fi first
    #define se second
    #define pb push_back
    #define ll long long
    #define ld long double
    #define pii pair<ll,ll>
    #define read(t) ll t;cin>>t;
    #define all(x) x.begin(),x.end()
    #define f(a,b,c) for(ll a=b;a<c;a++)
    #define For(i,n) for(ll i=0;i<n;i++)
    #define what(x) cerr << #x << " is " << x << endl;
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;
    typedef tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> ordered_mset;
    typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
/*.....................................................................................................................*/

    const ll mod=(ll)1e9+7;
    ll add(ll x,ll y) {return (x+y)%mod;}
    ll mult(ll x, ll y){return ((x%mod )* (y%mod)) % mod;}
    long long binpow(long long x, long long p) 
    {
        if (p == 0) {return 1;}
    	if (p == 2 || (p & 1)) {return mult(x, binpow(x, p - 1));}
    	return binpow(binpow(x, p / 2), 2);
    }
    ll modinv(ll a) {return binpow(a,mod-2);}
    double pi=3.141592653589793238462641;
    ll dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    const ll man=(ll)1e5+5;
/*........................................................................................................................*/

signed main()
{
    fast;
    ll n,m;
    cin>>n>>m;
    if(m<n)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}   
