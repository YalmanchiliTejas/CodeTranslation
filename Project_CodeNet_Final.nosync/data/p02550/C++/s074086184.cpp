#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll              long long
#define pb              push_back
#define ppb             pop_back
#define endl            '\n'
#define mii             map<ll,ll>
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define vs              vector<string>
#define all(a)          (a).begin(),(a).end()
#define F               first
#define S               second
#define sz(x)           ((ll)x.size())
//#define hell            (1000000007)
#define inf             ((ll)5e18 + 5)
#define PI              ((double)3.14159265358979323844)
#define DECIMAL(n)      cout << fixed << setprecision(n);
#define rep(i,a,b)      for (ll i=a;i<b;i++)
#define repr(i,a,b)     for (ll i=a-1;i>=b;i--)
#define bitcount(a)     (ll)__builtin_popcount(a)
#define lbnd            lower_bound
#define ubnd            upper_bound
#define mp              make_pair
#define ios             ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ordered_set     tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(...)      __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

using namespace std;
using namespace __gnu_pbds;

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

//primes for hashing 937,991,1013,1409,1741
ll hell;

ll add(ll a,ll b) {
    return ((a%hell)+(b%hell))%hell;
}
ll sub(ll a,ll b) {
    return ((a%hell)-(b%hell)+hell)%hell;
}
ll mul(ll a,ll b) {
    return ((a%hell)*(b%hell))%hell;
}
void solve() {
    ll n, x, m;
    cin>>n>>x>>m;
    if (n==1) {
        cout<<x<<endl;
        return;
    }
    hell=m;
    mii xxx;
    xxx[x]=1;
    vi v;
    v.pb(x);
    ll ind=1;
    ll prev=x;
    bool flag=false;
    ll last;
    while (1) {
        ll meow=mul(prev, prev);
        if (xxx.find(meow)!=xxx.end()) {
            last=xxx[meow];
            break;
        }
        ind++;
        xxx[meow]=ind;
        v.pb(meow);
        prev=meow;
        if (ind==n) {
            flag=true;
            break;
        }
    }
    if (flag) {
        ll ans=0;
        rep(i, 0, sz(v)) {
            ans+=v[i];
        }
        cout<<ans<<endl;
        return;
    }
    ll ans=0;
    ll p=last-1;
    ll q=ind-last+1;
    rep(i, 0, p) {
        ans+=v[i];
    }
    n-=p;
    ll temp2=0;
    rep(i, last-1, ind) {
        temp2+=v[i];
    }
    ans+=(n/q)*temp2;
    ll motu=last-1;
    rep(i, 0, n%q) {
        ans+=v[motu];
        motu++;
    }
    cout<<ans<<endl;
    // ll ans=0;
    // rep(i, 0, sz(v)) {
    //     ans+=v[i];
    // }
    // ans*=(n/ind);
    // rep(i, 0, n%ind) {
    //     ans+=v[i];
    // }
    // cout<<ans<<endl;
}

signed main() {
    ios
    ll test=1;
    //cin>>test;
    while (test--) solve();
    return 0;
}