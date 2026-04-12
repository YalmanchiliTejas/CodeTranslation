#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
 
#include<deque>
#define pi 3.141592653589793238
#include<chrono>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 1e5 + 1;
ll parent[N]; 
ll findset(ll a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = findset(parent[a]);
}
void unionset(ll a, ll b){
    a = findset(a);
    b = findset(b);
    if(a == b){
        return;
    }
    parent[b] = a;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        set<pair<ll,ll>> s;
        for(i = 0; i < n; i++){
            ll a, b;
            cin >> a >> b;
            s.insert({a ,b});
        }
        for(i = 1; i <= n; i++){
            parent[i] = i;
        }
        vector<tuple<ll,ll,ll>> x, y;
        ll cnt = 0;
        for(auto u : s){
            ll a, b, c;
            a = u.ff;
            b = u.ss;
            x.pb({a, b, ++cnt});
            y.pb({b, a, cnt});
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        vector<tuple<ll,ll,ll>> edges;
        for(i = 1; i < x.size(); i++){
            ll a, b, c;
            tie(a, b, c) = x[i];
            ll aa, bb ,cc;
            tie(aa ,bb, cc) = x[i - 1];
            ll wt;
            wt = min(abs(aa - a), abs(bb - b));
            edges.pb({wt, c, cc});
        }
        for(i = 1; i < y.size(); i++){
            ll a, b, c;
            tie(a, b, c) = y[i];
            ll aa, bb ,cc;
            tie(aa ,bb, cc) = y[i - 1];
            ll wt;
            wt = min(abs(aa - a), abs(bb - b));
            edges.pb({wt, c, cc});
        }
        ll ans = 0;
        sort(edges.begin(), edges.end());
        for(auto u : edges){
            ll a, b, c;
            tie(a, b, c) = u;
            if(findset(b) == findset(c)){
                continue;
            }
            unionset(b, c);
            ans += a;
        }
        cout << ans;
    }
    return 0;
}