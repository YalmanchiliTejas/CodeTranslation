#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define uint unsigned int
#define ull  unsigned long long
#define pb push_back
#define mk make_pair
#define ins insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define X first
#define Y second
#define umap unordered_map
#define speed() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define setvalue(d,s,e,n) for(int qwe = s; qwe < e; ++qwe) d[qwe] = n
#define mset multiset
#define pqueue priority_queue
   
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
        
const int  N = 2e5 + 314;
const int INF = 1e9;
const double PI = acos(-1);
int MOD = 1e9 + 7;
const double eps = 1e-9;
const long long LINF = 1e18 + 3141;
ll bp(ll a, ll n){
    ll res = 1;
    while(n) {
        if(n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}
ll get(ll n, vector <ll> &pf, vector <ll>& cyc) {
    ll ans = 0;
    ll pfsz = pf.size(), csz = cyc.size();
    // cout << pfsz << ' ' << csz << '\n';
    for(int i = 0; i < min(n, pfsz); ++i)
        ans += pf[i];
    if(n <= pfsz)
        return ans;
    n -= pf.size();
    ll sumcyc = accumulate(all(cyc), 0ll);
    ans += n / cyc.size() * sumcyc; 
    for(int i = 0; i < n % cyc.size(); ++i)
        ans += cyc[i];
    return ans; 
}
void solve(){
    ll n, x;
    cin >> n >> x >> MOD;
    vector <ll> t;
    t.pb(-1);
    t.pb(x);
    map <ll, int> fid;
    fid[x] = 1;
    ll e = n + 1, pv = x;
    for(int i = 2; i <= n; ++i) {
        ll cur = pv * pv % MOD;
        if(fid[cur]) {
            e = fid[cur];
            break;
        }
        fid[cur] = i;
        t.pb(cur);
        pv = cur;
    }
    vector <ll> pf, cyc;
    for(int i = 1; i < e; ++i) 
        pf.pb(t[i]);
    
    for(int i = e; i < t.size(); ++i) 
        cyc.pb(t[i]);
    
    cout << get(n, pf, cyc);
}
 
int main(){
    // speed();
    int t = 1;
    // cin >> t;
    while(t--)solve();
}