#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define pii pair<ll,ll>
#define tii tuple<ll,ll,ll>
#define all(v) (v).begin(),(v).end()
#define ll long long
#define deb(x) cout << #x << "=" << x << endl;
#define ull unsigned long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ld long double
#define mod 1000000007
#define PI 3.141592653589793238
#define phi 1.638
#define eps 1e-9
#define endl "\n"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;   

int main() {
    fastio
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(auto& it : vec) cin>>it;

    ll tot = accumulate(all(vec), 0ll)%mod;
    ll ans = 0;
    ll pref = 0;
    for(int i = 0; i<n; ++i) {
        pref += vec[i];
        pref %= mod;
        ll cur = (tot-pref+mod)%mod;
        ans += cur*vec[i];
        ans %= mod;
    }
    cout<<ans<<endl;
}