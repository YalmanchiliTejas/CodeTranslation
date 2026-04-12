#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
using namespace std;
// using cd = complex<double>;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;
 

typedef long long int ll;
typedef long double ld;
const ll N = 2e5 + 9;
const ll mod = 1e9 + 7;
const ll inf= 1e14;

const double PI = acos(-1);
#define x first
#define y second
#define pb push_back
#define mp make_pair    
#define pii pair<ll,ll>
#define pld pair<ld,ld>
ll powm(ll a, ll b,ll mod) { a = a%mod;ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    ll T = 1;
    // cin>>t;
    while(T--){
        ll n;cin>>n;
        ll a[n];
        ll su = 0;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            su+=a[i];
            su%=mod;
        }
        // cout<<su<<'\n';
        ll sub = 0,ans = 0;
        for(int i = 0;i<n;i++){
            sub+=a[i];
            sub%=mod;
            ans+=((su-sub +mod)%mod)*a[i];
            ans%=mod;

        }
        cout<<ans<<'\n';

    }
}