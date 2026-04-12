#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
// #define _GLIBCXX_DEBUG
template <class T> using V = vector<T>;
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1000000007LL;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

/*--------------------------------------------------------------------------------

--------------------------------------------------------------------------------*/

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    // ループを見つける　鳩ノ巣原理
    V<ll> a;
    set<ll> st;
    a.push_back(x); 
    st.insert(x);
    ll bf_st;
    while(1){
        ll b = *a.rbegin();
        ll c = b*b%m;
        bf_st = sz(st);
        a.push_back(c);
        st.insert(c);
        if(sz(st) == bf_st){ // ループを見つけた
            break;
        }
    }
    //debug
    // rep(i, 0, sz(a)) cout << a[i] << " \n"[i==sz(a)-1];
    //
    ll T = 0; // 周期
    ll bf_roop = 0; // ループに入るまで
    rep(i, 0, sz(a)){
        if(a[i] == *a.rbegin()){
            bf_roop = i;
            T = sz(a)-1 - i;
            break;
        }
    }
    //debug
    // cout << bf_roop << " " << T << endl;
    //
    ll bf_sum = 0; // ループに入るまでの和
    ll roop_sum = 0; // ループの和
    rep(i, 0, bf_roop) bf_sum += a[i];
    rep(i, bf_roop, bf_roop+T) roop_sum += a[i];
    //debug
    // cout << bf_sum << " " << roop_sum << endl;
    //
    ll ans = 0;
    if(n <= bf_roop){
        rep(i, 0, n) ans += a[i];
    }else{
        n -= bf_roop;
        ans += bf_sum;
        ll ro_cnt = n/T, nokori = n%T;
        ans += ro_cnt * roop_sum;
        rep(i, bf_roop, bf_roop+nokori) ans += a[i];
    }
    cout << ans << endl;

    return 0;
}