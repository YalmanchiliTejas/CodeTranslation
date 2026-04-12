#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

template<typename T>
struct SegmentTree{
private:
    int n, N;
    vector<T> node;
    function<T(T, T)> F;
    T E;
public:
    void init(int _n, function<T(T, T)> f, T e){
        F = f;
        E = e;
        n = _n;
        N = 1;
        while(N < n) N = (N<<1);
        node.assign(2*N-1, e);
    }
    void init(vector<T> v, function<T(T, T)> f, T e){
        F = f;
        E = e;
        n = v.size();
        N = 1;
        while(N < n) N = (N<<1);
        node.assign(2*N-1, e);
        for(int i=0; i<n; i++) node[N-1+i] = v[i];
        for(int i=N-2; i>=0; i--) node[i] = F(node[(i<<1)+1], node[(i<<1)+2]);
    }
    T& operator [](int a){
        return node[N-1+a];
    }
    void update(int a, T x){
        a += N-1;
        node[a] = x;
        while(a > 0){
            a = (a-1)>>1;
            node[a] = F(node[(a<<1)+1], node[(a<<1)+2]);
        }
    }
    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r == -1) r = N;
        if(b <= l || r <= a) return E;
        if(a <= l && r <= b) return node[k];
        return F(query(a, b, (k<<1)+1, l, (l+r)>>1), query(a, b, (k<<1)+2, (l+r)>>1, r));
    }
    int find_right(function<bool(T)> g, int a, int k=0, int l=0, int r=-1, T t=T()){
        if(r == -1){
            r = N;
            t = E;
            if(!g(t)) return -1;
        }
        if(r <= a || !g(t)) return a;
        if(r-l == 1) return g(F(t, node[k])) ? min(r, n) : a;
        if(a <= l){
            int R = find_right(g, a, (k<<1)+2, (l+r)>>1, r, F(t, node[(k<<1)+1]));
            if(R != a) return R;
            int L = find_right(g, a, (k<<1)+1, l, (l+r)>>1, t);
            if(L != a) return L;
            return a;
        }
        return max(find_right(g, a, (k<<1)+1, l, (l+r)>>1, t),
            find_right(g, a, (k<<1)+2, (l+r)>>1, r, F(query(a, (l+r)>>1), t)));
    }
    int find_left(function<bool(T)> g, int b, int k=0, int l=0, int r=-1, T t=T()){
        if(r == -1){
            r = N;
            t = E;
            if(!g(t)) return n + 1;
        }
        if(b <= l || !g(t)) return b;
        if(r-l == 1) return g(F(node[k], t)) ? l : b;
        if(r <= b){
            int L = find_left(g, b, (k<<1)+1, l, (l+r)>>1, F(node[(k<<1)+2], t));
            if(L != b) return L;
            int R = find_left(g, b, (k<<1)+2, (l+r)>>1, r, t);
            if(R != b) return R;
            return b;
        }
        return min(find_left(g, b, (k<<1)+1, l, (l+r)>>1, t),
            find_left(g, b, (k<<1)+2, (l+r)>>1, r, F(query((l+r)>>1, b), t)));
    }
};

int N, Q;
vector<int> A;
SegmentTree<int> st;
int T, X, Y;

signed main(){
    cin >> N >> Q;
    A.resize(N);
    rep(i, N) cin >> A[i];

    st.init(A, [](int a, int b){ return max(a, b); }, INT_MIN);
    rep(i, Q){
        cin >> T >> X >> Y;
        if(T == 1) st.update(X-1, Y);
        if(T == 2) cout << st.query(X-1, Y) << endl;
        if(T == 3) cout << st.find_right([](int a){ return a < Y; }, X-1) + 1 << endl;
    }
}