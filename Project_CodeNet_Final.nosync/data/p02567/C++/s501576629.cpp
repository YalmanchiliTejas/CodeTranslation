#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[9]={1,0,-1,0,1,1,-1,-1,0};
const ll dx[9]={0,-1,0,1,1,-1,1,-1,0};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
class SegTree {
    int n;// 葉の数
    vector<T> data;// データを格納するvector
    T def; // 初期値かつ単位元
    function<T(T, T)> operation; // 区間クエリで使う処理
    function<T(T, T)> update;// 点更新で使う処理

    T find(int a, int b) {
        ll val_left = def, val_right = def;
        for (a += (n - 1), b += (n - 1); a < b; a >>= 1, b >>= 1)
        {
            if ((a & 1) == 0){
                val_left = operation(val_left, data[a]);
            }
            if ((b & 1) == 0){
                val_right = operation(val_right, data[--b]);
            }
        }
        return operation(val_left, val_right);
    }
    public:
    // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
    // _update:更新関数
    SegTree(size_t _n, T _def, function<T(T, T)> _operation,
        function<T(T, T)> _update=[](T a,T b){return b;})
        : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }
    void set(int i, T x) { data[i + n - 1] = x; }
    void build() {
        for (int k=n-2;k>=0;k--) data[k] = operation(data[2*k+1],data[2*k+2]);
    }
    // 場所i(0-indexed)の値をxで更新
    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    // [a, b)の区間クエリを実行
    T query(int a, int b) {
        //return _query(a, b, 0, 0, n);
        return find(a,b);
    }

    // 添字でアクセス
    T operator[](int i) {
        return data[i + n - 1];
    }
};


int main(){
    ll n,q;cin >> n >>q;
    SegTree<ll> st(n,-INF,[](ll a,ll b){return max(a,b);});
    rep(i,n){
        ll a;cin >> a;
        st.set(i,a);
    }
    st.build();
    while(q--){
        ll t;cin >> t;
        if(t==1){
            ll x,v;cin >> x >> v;x--;
            st.change(x,v);
        }
        if(t==2){
            ll l,r;cin >> l >>r;l--;
            cout << st.query(l,r) <<endl;
        }
        if(t==3){
            ll x,v;cin >> x >> v;x--;
            ll ng=x-1,ok=n;
            while(abs(ok-ng)>1){
                ll mid=(ok+ng)/2;
                if(st.query(x,mid+1)>=v)ok=mid;
                else ng=mid;
            }
            cout << ok+1 <<endl;
        }
    }
}