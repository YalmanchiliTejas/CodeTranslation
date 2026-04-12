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
#define hell            (1000000007)
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


ll expo(ll base, ll exponent) {                     //return base^exponent modulo hell
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%hell;
        }
        base = base*base;
        base %= hell;
        exponent>>= 1;
    }
    return ans%hell;
}
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
    ll n;
    cin>>n;
    ll arr[n];
    ll sum=0, meow=0;
    rep(i, 0, n) {
        cin>>arr[i];
        sum=add(sum, arr[i]);
        meow=add(meow, mul(arr[i], arr[i]));
    }
    sum=mul(sum, sum);
    ll temp=sub(sum, meow);
    cout<<mul(temp,expo(2, hell-2))<<endl;
}

signed main() {
    ios
    ll test=1;
    //cin>>test;
    while (test--) solve();
    return 0;
}