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

struct RMaxQ{
private:
    int N;
    vector<long long> node, lazy;
    vector<bool> lazyFlg;
    long long DEFAULT;
public:
    void init(int n, long long def=-9223372036854775807LL){
        DEFAULT = def;
        node.clear();
        lazy.clear();
        lazyFlg.clear();
        N = 1;
        while(N < n) N = (N<<1);
        for(int i=0; i<2*N-1; i++){
            node.push_back(DEFAULT);
            lazy.push_back(0LL);
            lazyFlg.push_back(false);
        }
    }
    void eval(int k, int l, int r){
        if(lazyFlg[k]){
            node[k] = lazy[k];
            if(r-l > 1){
                lazy[(k<<1)+1] = lazy[k];
                lazyFlg[(k<<1)+1] = true;
                lazy[(k<<1)+2] = lazy[k];
                lazyFlg[(k<<1)+2] = true;
            }
            lazy[k] = 0LL;
            lazyFlg[k] = false;
        }
        else{
            node[k] += lazy[k];
            if(r-l > 1){
                lazy[(k<<1)+1] += lazy[k];
                lazy[(k<<1)+2] += lazy[k];
            }
            lazy[k] = 0LL;
        }
    }
    void update(int a, long long x){
        update(a, a+1, x);
    }
    void update(int a, int b, long long x, int k=0, int l=0, int r=-1){
        if(a >= b) return;
        if(r == -1) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] = x;
            lazyFlg[k] = true;
            eval(k, l, r);
        }
        else{
            update(a, b, x, (k<<1)+1, l, (l+r)>>1);
            update(a, b, x, (k<<1)+2, (l+r)>>1, r);
            node[k] = std::max(node[(k<<1)+1], node[(k<<1)+2]);
        }
    }
    void add(int a, long long x){
        add(a, a+1, x);
    }
    void add(int a, int b, long long x, int k=0, int l=0, int r=-1){
        if(a >= b) return;
        if(r == -1) r = N;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] += x;
            eval(k, l, r);
        }
        else{
            add(a, b, x, (k<<1)+1, l, (l+r)>>1);
            add(a, b, x, (k<<1)+2, (l+r)>>1, r);
            node[k] = std::max(node[(k<<1)+1], node[(k<<1)+2]);
        }
    }
    long long max(int a, int b, int k=0, int l=0, int r=-1){
        if(a >= b) return -9223372036854775807LL;
        if(r == -1) r = N;
        if(b <= l || r <= a) return -9223372036854775807LL;
        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        return std::max(max(a, b, (k<<1)+1, l, (l+r)>>1), max(a, b, (k<<1)+2, (l+r)>>1, r));
    }
    int find(int a, int b, long long m, int k=0, int l=0, int r=-1){
        if(r == -1){
            r = N;
        }
        if(r <= a || b <= l) return INT_MAX;
        if(r-l == 1){
            if(node[k] >= m) return l;
            else return INT_MAX;
        }
        if(a <= l && r <= b){
            long long valueL = max(a, b, (k<<1)+1, l, (l+r)>>1);
            long long valueR = max(a, b, (k<<1)+2, (l+r)>>1, r);
            if(valueL >= m) return find(a, b, m, (k<<1)+1, l, (l+r)>>1);
            if(valueR >= m) return find(a, b, m, (k<<1)+2, (l+r)>>1, r);
            return INT_MAX;
        }
        return std::min(find(a, b, m, (k<<1)+1, l, (l+r)>>1), find(a, b, m, (k<<1)+2, (l+r)>>1, r));
    }
};

int N, Q;
int A[200000];
RMaxQ rmq;

signed main(){
    cin >> N >> Q;
    rep(i, N){
        cin >> A[i];
    }

    rmq.init(N);
    rep(i, N) rmq.update(i, A[i]);
    rep(i, Q){
        int T, X, Y;
        cin >> T >> X >> Y;
        if(T == 1) rmq.update(X-1, Y);
        if(T == 2) cout << rmq.max(X-1, Y) << endl;
        if(T == 3) cout << min(rmq.find(X-1, N, Y), N)+1 << endl;
    }
}