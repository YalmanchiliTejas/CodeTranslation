#include <bits/stdc++.h>
//#include <chrono>
//#pragma GCC optimize("Ofast")
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,Q,K,A,B;
string S;
typedef pair<ll, ll> P;
const ll INF = (1LL<<60);

class SEGTREE {
    unsigned int n;
    ll dflt;
    vector<ll> dat;

    static ll op(const ll a, const ll b) {
        return max(a, b);
    }

    bool f(const unsigned int id, const ll a){
        return dat[id] >= a;
    }

public:
    SEGTREE(unsigned long _n, ll _a) : n(1), dflt(_a) {
        while (n < _n) {n *= 2;}
        dat.resize(n * 2, dflt);
    }

    void update(unsigned int k, ll a) {
        k += n;
        dat[k] = a;
        while (k > 0) {
            k >>= 1;
            dat[k] = op(dat[k<<1], dat[(k<<1)|1]);
        }
    }

    void init(vector<ll> &v) {
        for (int i = 0; i < (int)v.size(); ++i) dat[i + n] = v[i];
        for (int i = n - 1; i >= 1; --i) {
            dat[i] = op(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    ll query(unsigned int l, unsigned int r) {
        ll res_left = dflt, res_right = dflt;
        l += n; r += n;
        for ( ; l < r; l >>= 1, r >>= 1){
            if(l&1){
                res_left = op(res_left, dat[l]);
                if((++l) == r) break;
            }
            if(r&1){
                res_right = op(dat[r ^ 1], res_right);
            }
        }
        return op(res_left, res_right);
    }

    unsigned int max_right_search(unsigned int id, ll a){
        while(id < n) id = (id<<1) | !f(id<<1, a);
        return id - n;
    }

    unsigned int max_right(unsigned int l, unsigned int r, ll a){
        //[l, r)内のindexであるjであって、query(l, j) < a <= query(l, j + 1)なるものを求める
        //つまり、j >= l かつ dat[j] >= a である最小の数jを求める(func = maxの場合)
        unsigned int see_after = r + n;
        l += n;
        for (unsigned int tr = r + n ; l < tr; l >>= 1, tr >>= 1){
            if(l&1){
                if(f(l, a)) return max_right_search(l, a);
                if((++l) == tr) break;
            }
            if((tr&1) && f(tr ^ 1, a)) see_after = tr ^ 1;
        }
        return see_after == r + n ? r : max_right_search(see_after, a);
    }

    //単項にアクセスする[]だが、書き換え厳禁
    //一応後でinitすれば書き換えてもよさそうだが…
    ll &operator[](int k) { return dat[k + n]; }
};
int main() {
    cin>>N>>Q;
    vec a(N);
    rep(i, N) scanf("%lld", &a[i]);
    SEGTREE seg(N, 0);
    seg.init(a);
    rep(_, Q){
        int t, x, v, l, r;
        scanf("%d", &t);
        if(t == 1){
            scanf("%d%d", &x, &v); --x;
            seg.update(x, v);
        }else if(t == 2){
            scanf("%d%d", &l, &r);
            printf("%lld\n", seg.query(l - 1, r));
        }else{
            scanf("%d%d", &x, &v); --x;
            printf("%u\n", seg.max_right(x, (unsigned int) N, v) + 1);
        }
    }
}

