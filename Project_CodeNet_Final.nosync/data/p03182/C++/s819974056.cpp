#include <bits/stdc++.h>
#define ll long long
#define INF (1LL << 60)
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 200005;

template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            if(k < n) {
                lazy[k*2] += lazy[k], lazy[k*2+1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(vector<T>& v) : sz((int)v.size()), h(0) {
        n = 1;
        while(n < sz) n *= 2, h++;
        node.resize(2*n, numeric_limits<T>::min());
        lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = max(node[2*i], node[2*i+1]);
    }
    void range(int a, int b, T x) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        int ta = a, tb = b++;
        while(a < b){
            if(a & 1) lazy[a++] += x;
            if(b & 1) lazy[--b] += x;
            a >>= 1, b >>= 1;
        }
        while(ta >>= 1, tb >>= 1, ta){
            if(!lazy[ta]){
                eval(2*ta), eval(2*ta+1), node[ta] = max(node[2*ta], node[2*ta+1]);
            }
            if(!lazy[tb]){
                eval(2*tb), eval(2*tb+1), node[tb] = max(node[2*tb], node[2*tb+1]);
            }
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = numeric_limits<T>::min(), res2 = numeric_limits<T>::min();
        while(a < b) {
            if(a & 1) eval(a), res1 = max(res1, node[a++]);
            if(b & 1) eval(--b), res2 = max(res2, node[b]);
            a >>= 1, b >>= 1;
        }
        return max(res1, res2);
    }
    void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

// struct info {
//     int l, r;
//     ll a;
//     bool operator< (const info& another) const {
//         return (l == another.l)?(r < another.r):(l < another.l);
//     }
// };
// 
// info vec[MAX_N];

vector<P> ev[MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i,m){
        int l,r,a;
        cin >> l >> r >> a;
        ev[l-1].pb(P(a,-1));
        ev[r].pb(P(a,l-1));
    }
    vl hoge(n+1, 0);
    segtree<ll> sg(hoge);
    ll ans = 0;
    rep(i,n){
        each(it,ev[i]){
            if(it.se < 0){
                sg.range(0,i+1,it.fi);
            }else{
                sg.range(0,it.se+1,-it.fi);
            }
        }
        ll res = sg.query(0, i+1);
        cmx(ans, res);
        sg.range(i+1, i+2, res-sg.query(i+1, i+2));
        // sg.print();
    }
    cout << ans << "\n";
    return 0;
}