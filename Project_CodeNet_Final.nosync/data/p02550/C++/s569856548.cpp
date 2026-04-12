#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define pii pair<ll,ll>
#define ll long long
#define tii tuple<ll,ll,ll>
#define all(v) (v).begin(),(v).end()
#define deb(x) cout << #x << "=" << x << endl;
#define ull unsigned long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define ld long double
#define mod 998244353
#define PI 3.141592653589793238
#define phi 1.638
#define eps 1e-9
#define endl "\n"
using namespace std;
using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;      



int main() {
    fastio
    ll n, x, m;
    cin>>n>>x>>m;

    ll ans = x;
    ll cnt = 1;
    vector<ll> v = {x};
    map<ll, int> mp;
    mp[x] = 1;
    ll rep = 0;
    while(x != 0 && cnt<n) {
        x *= x;
        x %= m;
        if(x == 0) {
            cout<<ans<<endl;
            return 0;
        }

        if(mp[x]) {
            rep = x;
            break;
        }

        v.push_back(x);
        mp[x] = 1;

        ans += x;
        cnt++;
    }

    int ind = 0;
    for(int i = 0; i<v.size(); ++i) {
        if(v[i] == x) {
            ind = i;
            break;
        }
    }
    ll len = v.size() - ind;

    ll rem = n - cnt;
    ans += (rem/len)*(accumulate(v.begin()+ind, v.end(), 0ll));
    ans += accumulate(v.begin()+ind, v.begin()+ind+(rem%len), 0ll);
    cout<<ans<<endl;
}