#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// #define int ll
using PII = pair<ll, ll>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()

template<typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }
template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }

template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type
fill_v(T &t, const V &v) { t=v; }
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t, const V &v ) { for(auto &e:t) fill_v(e,v); }

template<class S,class T>
ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.first<<','<<a.second<<')'; return out;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x: vec) {is >> x;} return is;
}
template<class T>
ostream &operator <<(ostream& out,const vector<T>& a){
    out<<'['; for(T i: a) {out<<i<<',';} out<<']'; return out;
}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}; // DRUL
const int INF = 1<<30;
const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;

ll binpow(ll x, ll e) {
  ll ret = 1, p = x;
  while(e > 0) {
    if(e&1) {(ret *= p) %= MOD; e--;}
    else {(p *= p) %= MOD; e /= 2;} 
  }
  return ret;
}

PII dfs(vector<ll> a) {
    ll n = a.size();
    // 最小の要素の分引く
    ll mi = *min_element(ALL(a)), cnt = 0;
    REP(i, n) {
        a[i] -= mi;
        cnt += a[i]==0;
    }
    // 子が存在しない
    if(cnt == n) {
        ll ans = binpow(2, n);
        (ans += MOD-2) %= MOD;
        (ans += binpow(2, mi)) %= MOD;
        // cout << a << " " << mi << " " << PII{binpow(2, mi), ans} << endl;
        return {binpow(2, mi), ans};
    }
    // a[i]=0のところで分割して子を求める
    ll l = 0;
    vector<vector<ll>> child;
    while(l < n) {
        if(a[l] == 0) {l++; continue;}
        ll r = l;
        while(r+1<n && a[r+1] > 0) ++r;
        vector<ll> c;
        FOR(i, l, r+1) c.push_back(a[i]);
        child.push_back(c);
        l = r+1;
    }
    // 子の答えを求める
    vector<PII> ret;
    for(auto c: child) ret.push_back(dfs(c));
    ll ans1 = 1, ans2 = 1;
    for(auto p: ret) {
        (ans1 *= p.first) %= MOD;
        (ans2 *= (p.first + p.second)) %= MOD; 
    }
    PII ans;
    ans.first = binpow(2, mi) * ans1 % MOD;
    ans.second = binpow(2, cnt) * ans2 % MOD;
    (ans.second += (binpow(2, mi) + MOD - 2) % MOD * ans1 % MOD) %= MOD;
    // cout << a << " " << mi << " " << ans << endl;
    return ans;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> h(n);
    REP(i, n) cin >> h[i];

    cout << dfs(h).second << endl;

    return 0;
}
