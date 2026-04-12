#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==v.size()-1?']':','); return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

template<typename T,typename MERGE,typename UPDATE>
class lazy_segtree {
    int n;
    vector<T> val,lazy;
    T identity_merge,identity_update;
    MERGE merge; // (T,T) -> T
    // update value for specified times
    UPDATE _update; // (T,T,int) -> T
    void eval(int k,int l,int r) {
        if(lazy[k] == identity_update) return;
        if(k < n-1) {
            lazy[k*2+1] = _update(lazy[k*2+1],lazy[k],1);
            lazy[k*2+2] = _update(lazy[k*2+2],lazy[k],1);
        }
        val[k] = _update(val[k],lazy[k],r-l);
        lazy[k] = identity_update;
    }

public:
    lazy_segtree(int _n,vector<T> init,T identity_merge,T identity_update,
                 MERGE merge,UPDATE update)
            :identity_merge(identity_merge),identity_update(identity_update),merge(merge),_update(update) {
        n = 1;
        while(n < _n) n *= 2;
        val = vector<T>(2*n-1,identity_merge);
        lazy = vector<T>(2*n-1,identity_update);
        rep(i,_n) val[i+n-1] = init[i];
        rrep(i,n-1) val[i] = merge(val[i*2+1],val[i*2+2]);
    }
    void update(int a,int b,T x,int k = 0,int l = 0,int r = -1) {
        if(r == -1) r = n;
        eval(k,l,r);
        if(a <= l && r <= b) {
            lazy[k] = _update(lazy[k],x,1);
            eval(k,l,r);
        } else if(a < r && l < b) {
            update(a,b,x,k*2+1,l,(l+r)/2);
            update(a,b,x,k*2+2,(l+r)/2,r);
            val[k] = merge(val[k*2+1],val[k*2+2]);
        }
    }
    // segment [a,b)
    T query(int a,int b,int k = 0,int l = 0,int r = -1) {
        if(r == -1) r = n;
        eval(k,l,r);
        if(b <= l || r <= a) return identity_merge;
        if(a <= l && r <= b) return val[k];
        T t1 = query(a,b,2*k+1,l,(l+r)/2);
        T t2 = query(a,b,2*k+2,(l+r)/2,r);
        return merge(t1,t2);
    }
    pair<T,T> operator[](int i) const { return make_pair(val[i],lazy[i]); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vp> v(n);
    rep(i,m) {
        int l,r,a;
        cin >> l >> r >> a;
        l--; r--;
        v[r].eb(l,a);
    }
    auto f = [](ll a,ll b){ return max(a,b); };
    auto g = [](ll a,ll b,int c){ return a+b; };
    lazy_segtree<ll, decltype(f), decltype(g)> st(n+1,vl(n+1,0),-linf,0,f,g);
    rep(i,n) {
//        cout << i << endl;
        st.update(i+1,i+2,st.query(0,i+1)-st.query(i+1,i+2));
//        rep(j,n+1) cout << st.query(j,j+1) << endl;
        for(P p : v[i]) {
//            cout << "-u-" << p << endl;
            st.update(p.first+1,i+2,p.second);
        }
//        rep(j,n+1) cout << st.query(j,j+1) << endl;
    }
    cout << st.query(0,n+1) << endl;
}
