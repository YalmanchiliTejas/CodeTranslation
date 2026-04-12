#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<typename Monoid>
struct Segment_Tree{
    vector<Monoid> seg;
    const Monoid unit;
    const int n;

    Monoid f(Monoid a, Monoid b) const {return max(a, b);}
    
    Segment_Tree(int N, const Monoid &unit) : unit(unit), n(1<<(32-__builtin_clz(N-1))){
        seg.assign(2*n, unit);
    }
    
    void change(int i, const Monoid &x){
        i += n;
        seg[i] = x;
        while(i > 0){
            i /= 2;
            seg[i] = f(seg[2*i], seg[2*i+1]);
        }
    }

    Monoid query(int a, int b, int i = 1, int l = 0, int r = -1) const{
        if(r < 0) r = n;
        if(a >= r || b <= l) return unit;
        if(a <= l && r <= b) return seg[i];
        Monoid vl = query(a, b, 2*i, l, (l+r)/2);
        Monoid vr = query(a, b, 2*i+1, (l+r)/2, r);
        return f(vl, vr);
    }
    
    Monoid operator [] (int i) const {return seg[n+i];}

    int find_first(int a, const Monoid &x, int i = 1, int l = 0, int r = -1) const{
        if(r < 0) r = n;
        if(seg[i] < x) return -1;
        if(r-l == 1) return l;
        int m = (l+r)/2;
        if(a < m){
            int tmp = find_first(a, x, 2*i, l, m);
            return (tmp == -1? find_first(m, x, 2*i+1, m, r) : tmp);
        }
        return find_first(a, x, 2*i+1, m, r);
    }
    
    void clear(){
        fill(all(seg), unit);
    }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    Segment_Tree<int> seg(N, -inf);
    rep(i, N){
        int A; cin >> A;
        seg.change(i, A);
    }
    while(Q--){
        int q, a, b; cin >> q >> a >> b; a--;
        if(q == 1) seg.change(a, b);
        if(q == 2) cout << seg.query(a, b) << endl;
        if(q == 3){
            int ans = seg.find_first(a, b);
            cout << (ans == -1? N+1 : ans+1) << endl;
        }
    }
}