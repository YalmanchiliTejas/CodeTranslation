#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

const int MAX_N = 3 * 1e5;

struct UnionFind{
    int N;
    int par[MAX_N];

    UnionFind(int N): N(N){
        for (int i=0;i<N;i++){
            par[i] = i;
        }
    }

    int root(int x){
        if(par[x] == x) return x;
        int rx = root(par[x]);
        par[x] = rx;
        return rx;
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx==ry) return;
        par[rx] = ry;
    }

    bool find(int x, int y){
        return root(x) == root(y);
    }
};

struct diff{
    ll s, t, w;
    bool operator<( const diff& right ) const {
        return w < right.w;
    }
};

int main(){
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    REP(i, N) cin >> x[i] >> y[i];
    vector<pii> xsort(N), ysort(N);
    REP(i, N){
        xsort[i].first = x[i];
        xsort[i].second = i;
        ysort[i].first = y[i];
        ysort[i].second = i;
    }
    sort(xsort.begin(), xsort.end());
    sort(ysort.begin(), ysort.end());
    vector<diff> diffs;
    REP(i, N-1){
        diff d;
        d.s = xsort[i].second;
        d.t = xsort[i+1].second;
        d.w = xsort[i+1].first - xsort[i].first;
        diffs.push_back(d);
    }
    REP(i, N-1){
        diff d;
        d.s = ysort[i].second;
        d.t = ysort[i+1].second;
        d.w = ysort[i+1].first - ysort[i].first;
        diffs.push_back(d);
    }
    sort(diffs.begin(), diffs.end());
    UnionFind uf(N);
    ll res = 0;
    REP(i, diffs.size()){
        if(!uf.find(diffs[i].s, diffs[i].t)){
            res += diffs[i].w;
            uf.unite(diffs[i].s, diffs[i].t);
        }
    }
    cout << res << endl;
    return 0;
}