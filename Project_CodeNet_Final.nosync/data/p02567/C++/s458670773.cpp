#include <bits/stdc++.h>
#include "atcoder/all"
using namespace std;
using namespace atcoder;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
const long long int sMod = 998244353;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll op(ll a,ll b){
    return max(a,b);
}

ll e(){
    return -1;
}

ll target;

bool f(ll x){
    return x < target;
}

void solve(){
    ll n,q;
    cin >> n >> q;
    Vi a(n);
    rp(i,n) cin >> a[i];
    segtree<ll,op,e> seg(a);
    Vi ans;
    while(q--){
        ll t;
        cin >> t;
        if(t==1){
            ll x,v;
            cin >> x >> v;
            x--;
            seg.set(x,v);
        }
        if(t==2){
            ll l,r;
            cin >> l >> r;
            l--;
            ans.pb(seg.prod(l,r));
        }
        if(t==3){
            ll x;
            cin >> x >> target;
            x--;
            ans.push_back(seg.max_right<f>(x)+1);
        }
    }
    for(auto an:ans){
        print(an);
    }
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}