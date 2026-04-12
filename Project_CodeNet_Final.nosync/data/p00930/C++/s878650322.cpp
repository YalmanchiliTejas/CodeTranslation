#include <bits/stdc++.h>
 
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
 
#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=(int)(a)-1;i>=(int)(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)
 
#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
 
// #define DEBUG
 
#ifdef DEBUG
    #define dump(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dump(...)
#endif
 
template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}
 
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
 
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int inf =1 << 30;
const ll mod=1000000007LL;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
 
ll extgcd(ll a,ll b,ll& x,ll& y){x=1,y=0;ll g=a;if(b!=0) g=extgcd(b,a%b,y,x),y-=a/b*x;return g;}
ll ADD(const ll &a, const ll &b,const ll &mod) { return (a+b)%mod;}
ll SUB(const ll &a, const ll &b,const ll &mod) { return (a-b+mod)%mod;}
ll MUL(const ll &a, const ll &b,const ll &mod) { return (1LL*a*b)%mod;}
ll DIV(const ll &a, const ll &b,const ll &mod) {ll x,y; extgcd(b,mod,x,y);return MUL(a,(x+mod)%mod,mod);}
 
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dice(1,6);
uniform_real_distribution<double> score(0.0,10.0);

struct SegTree {
    int n;
    vi lazy, d_min;

    int c1(int k) { return 2 * k + 1; }
    int c2(int k) { return 2 * k + 2; }

    SegTree(int sz){
        n = 1;
        while(n < sz) n *= 2;
        d_min = vi(2 * n, inf);
        lazy = vi(2 * n, 0);
    }
    SegTree(){}

    void update(int k, int l, int r){
        int& cur = lazy[k];
        if(cur == 0) return;

        if(d_min[k] == inf) d_min[k] = 0;
        d_min[k] += cur;

        if(r - l > 1){
            lazy[c1(k)] += cur;
            lazy[c2(k)] += cur;
        }
        cur = 0;
    }

    void add(int a, int b, int x, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        update(k, l, r);

        if(a >= r or l >= b) return;
        if(a <= l and r <= b){
            lazy[k] += x;
            update(k, l, r);
            return;
        }
        
        add(a, b, x, c1(k), l, (l + r) / 2);
        add(a, b, x, c2(k), (l + r) / 2, r);
        
        if(r - l > 1){
            d_min[k] = min(d_min[c1(k)], d_min[c2(k)]);
        }
    }

    int get_min(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        update(k, l, r);

        if(a >= r or l >= b) return inf;
        if(a <= l and r <= b){
            return d_min[k];
        }
        
        return min(get_min(a, b, c1(k), l, (l + r) / 2),
                   get_min(a, b, c2(k), (l + r) / 2, r));
    }
};

int n;
SegTree seg;

bool check(int l, int r){
    return seg.get_min(l, r) >= 2;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q; cin >> n >> Q;
    string in; cin >> in;
    set<int> s;
    vi a(n); rep(i, n) a[i] = (in[i] == '(' ? +1:-1);
    rep(i, n) if(a[i] < 0) s.insert(i);

    seg = SegTree(n);
    rep(i, n) seg.add(i, n, a[i]);

    rep(loop, Q){
        int x; cin >> x; x--;
        int idx;
        int cur = a[x];
        seg.add(x, n, cur * -2);

        // rep(i, n) cerr << seg.get_min(i, i + 1) << " "; cerr << endl;
        if(cur > 0){
            s.insert(x);
            idx = *begin(s);
            s.erase(idx);
        }
        else {
            int lb = -1, ub = x;
            while(ub - lb > 1){
                int mid = (lb + ub) / 2;
                if(check(mid, x + 1)){
                    ub = mid;
                }
                else {
                    lb = mid;
                }
            }
            idx = ub;
            s.erase(x);
            s.insert(idx);
        }
        a[idx] *= -1;
        a[x] *= -1;
        seg.add(idx, n, cur * 2);
        cout << idx+1 << endl;
    }

    return 0;
}