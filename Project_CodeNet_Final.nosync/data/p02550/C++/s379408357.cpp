#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1<<30;
const ll inf_l = 1LL<<61;
const int MAX = 1e5;

ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    ll n, x; cin >> n >> x;
    int m; cin >> m;
    vll data = {x};
    set<int> st;
    st.insert(x);
    int ct = 1;
    while (ct < n) {
        x = modpow(x,2,m);
        if (st.count(x)) break; 
        data.push_back(x);
        st.insert(x);
        ct++;
    }
    vll sum(data.size()+1,0);
    REP(i,data.size()+1) {
        sum[i] += sum[i-1] + data[i-1];
    }
    int id;
    rep(i,data.size()) if (data[i] == x) id = i;
    int len = data.size() - id;
    n -= data.size();
    ll ans = 0;
    ans += sum[data.size()];
    ans += (sum[data.size()] - sum[id]) * (n/len);
    n %= len;
    ans += sum[id+n] - sum[id];
    cout << ans << endl;
}