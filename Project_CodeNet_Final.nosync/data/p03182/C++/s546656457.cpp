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

// RAQ and RSQ
template<typename T> class segtree{
private:
    int n,sz;
    vector<T> node, lazy;

public:
    segtree(vector<T>& v){
        sz = (int)v.size();
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.resize(2*n-1, numeric_limits<T>::min());
        lazy.resize(2*n-1, 0);
        rep(i,sz){
            node[i+n-1] = v[i];
        }
        for(int i=n-2; i>=0; i--){
            node[i] = max(node[i*2+1], node[i*2+2]);
        }
    }
    void eval(int k, int l, int r){
        if(lazy[k] != 0){
            node[k] += lazy[k]; //kを根とするsubtreeについての情報を更新
            if(r - l > 1){
                lazy[2*k+1] += lazy[k], lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    void range(int a, int b, T x, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            lazy[k] += x;
            eval(k, l, r);
        }else{
            range(a, b, x, 2*k+1, l, (l+r)/2);
            range(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }
    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a){
            return numeric_limits<T>::min();
        }
        if(a <= l && r <= b){
            return node[k];
        }
        T vl = query(a, b, 2*k+1, l, (l+r)/2);
        T vr = query(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
    void print(){rep(i,sz)cout<<query(i,i+1)<< " ";cout<<endl;}
};

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