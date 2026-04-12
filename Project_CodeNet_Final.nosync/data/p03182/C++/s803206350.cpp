#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <unordered_map>
#include <random>

using namespace std;

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define Debug1(a)           cout<<#a<<"="<<(a)<<"\n"
#define Debug2(a,b)         cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define Debug3(a,b,c)       cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define Debug4(a,b,c,d)     cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define Debug5(a,b,c,d,e)   cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define Debug6(a,b,c,d,e,f) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
#define Debug(...) macro_dispatcher(Debug, __VA_ARGS__)(__VA_ARGS__)
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cout<<"]\n"

#define TT1 template<class T>
#define TT1T2 template<class T1, class T2>
#define TT1T2T3 template<class T1, class T2, class T3>
template<class T, size_t N> ostream& operator << (ostream& os, const array<T, N>& v);
TT1T2 ostream& operator << (ostream& os, const pair<T1, T2>& p){ return os <<"("<<p.first<<", "<< p.second<<")"; }
TT1 ostream& operator << (ostream& os, const vector<T>& v){       bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
template<class T, size_t N> ostream& operator << (ostream& os, const array<T, N>& v) {     bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const set<T1, T2>&v){    bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multiset<T1,T2>&v){bool f=1;os<<"[";for(auto& i : v) { if (!f)os << ", ";os<<i;f=0;}return os << "]"; }
TT1T2T3 ostream& operator << (ostream& os, const map<T1,T2,T3>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, const multimap<T1, T2>& v){ bool f = 1; os << "["; for (auto& ii : v) { if (!f)os << ", "; os << "(" << ii.first << " -> " << ii.second << ") "; f = 0; }return os << "]"; }
TT1T2 ostream& operator << (ostream& os, priority_queue<T1, T2> v) { bool f = 1; os << "["; while (!v.empty()) { auto x = v.top(); v.pop(); if (!f) os << ", "; f = 0; os << x; } return os << "]"; }
TT1T2 void printarray(const T1& a, T2 sz, T2 beg = 0){ for (T2 i = beg; i<sz; i++) cout << a[i] << " "; cout << endl; }

void cio(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

#define tt() printf("%.4f sec\n", (double) clock() / CLOCKS_PER_SEC )

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define repp(i, n) for(int i=1;i<=n;i++)
#define all(x) x.begin(), x.end()
#define geti1(X) cin >> X
#define geti2(X,Y) cin >> X >> Y
#define geti3(X,Y,Z) cin >> X >> Y >> Z
#define geti4(X,Y,Z,W) cin >> X >> Y >> Z >> W
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define geti(...) GET_MACRO(__VA_ARGS__, geti4, geti3, geti2, geti1) (__VA_ARGS__)

#define endl '\n'

typedef tuple<int,int,int> t3;
typedef tuple<int,int,int,int> t4;
void die(){printf("-1\n"); exit(0);}
int xx[4] = {1,-1,0,0}, yy[4] = {0,0,1,-1};

struct segTree{
    int n; vector<ll> d,lazy;
    void init(int x){
        n = 1; while( n < x ) n *= 2;
        d.resize(n*2+10); lazy.resize(n*2+10);
    }
    void propagate(int x){
        if( lazy[x] && x*2+1 < sz(d) ){
            d[x*2] += lazy[x]; d[x*2+1] += lazy[x];
            lazy[x*2] += lazy[x]; lazy[x*2+1] += lazy[x];
            d[x] = max(d[x*2], d[x*2+1]);
        }
        lazy[x] = 0;
    }
    void update(int node, int nl, int nr, int l, int r, ll val){
        if( r < l ) return;
        propagate(node);
        if( nr < l || r < nl ) return;
        if( l <= nl && nr <= r ){
            d[node] += val; lazy[node] += val;
            return;
        }
        update(node*2, nl, (nl+nr)/2, l, r, val);
        update(node*2+1, (nl+nr)/2+1, nr, l, r, val);
        d[node] = max(d[node*2], d[node*2+1]);
    }
    ll query(int node, int nl, int nr, int l, int r){
        if( r < l ) return - 1e18;
        propagate(node);
        if( nr < l || r < nl ) return -1e18;
        if( l <= nl && nr <= r ) return d[node];
        ll v1 = query(node*2, nl, (nl+nr)/2, l, r);
        ll v2 = query(node*2+1, (nl+nr)/2+1, nr, l, r);
        return max(v1,v2);
    }
};

int N,M;
segTree tree;
vector<pll> open[200500], close[300500];
int main() {
    scanf("%d%d",&N,&M); tree.init(N+2);
    repp(i,M){
        ll l,r,a; scanf("%lld%lld%lld",&l,&r,&a);
        open[l].push_back({r,a});
        close[r].push_back({l,a});
    }
    ll sum = 0, ans = 0;
    for(int i=1;i<=N;i++){
        for(auto e : open[i]){
            tree.update(1, 1, tree.n, 1, i-1, e.Se);
            sum += e.Se;
        }
        
        //for(int i=1;i<=N;i++) printf("%lld ",tree.query(1, 1, tree.n, i, i) ); printf("\n");
        ll ret = tree.query(1, 1, tree.n, 1, i-1);
        ans = max(ans, sum); ans = max(ans, ret);
        tree.update(1, 1, tree.n, i, i, max(sum, ret));
        for(auto e : close[i]){
            tree.update(1, 1, tree.n, 1, e.Fi-1, -e.Se);
            sum -= e.Se;
        }
    }
    printf("%lld\n",ans);
}

