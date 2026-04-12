//----------------------------おまじない
#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
//----------------------------
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>=0;i--)
#define I(n) scanf("%d", &(n))
#define LL(n) scanf("%lld", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#define eb(i,j) emplace_back((i),(j))
#include <bits/stdc++.h>
using namespace std;
//------------------------------typedef集
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vvi> vvvi;
typedef long long ll;
const int mod = 1000000009;

class UnionFind {
    private:
        vi par;    // x の親ノード
        vi rank;   // 木の高さ
        vi mem;    // メンバの数
        int sz;             // 集合の個数
    public:
        UnionFind(int n) :
            par(n, -1), rank(n, 0), mem(n, 1), sz(n) {
            REP(i,n) par[i] = i;
        }
    
    int size() { return sz; }

    // 集合の追加
    void makeset() {
        par.pb(par.size());
        rank.pb(0);
        mem.pb(1);
        sz++;
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    int member(int x){
        x = find(x);
        return mem[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]){
            par[x] = y;
            mem[x] += mem[y];
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
            mem[y] += mem[x];
        }
        sz--;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int n,xi,yi;
vpi x,y;


int main(){
    I(n);
    x.resize(n);
    y.resize(n);
    REP(i,n){
        I(xi); I(yi);
        x[i] = mp(xi,i);
        y[i] = mp(yi,i);        
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    priority_queue< pair<int,pi>, vector<pair<int,pi>>,greater<pair<int,pi>>> pq;
    REP(i,n-1){
        pq.push(mp(x[i+1].first-x[i].first,mp(x[i].second,x[i+1].second)));
        pq.push(mp(y[i+1].first-y[i].first,mp(y[i].second,y[i+1].second)));
    }
    UnionFind uf = UnionFind(n);
    ll ret = 0;
    while(n-1){
        auto pqtop = pq.top();
        pq.pop();
        xi = pqtop.second.first;
        yi = pqtop.second.second;
        if(!uf.same(xi,yi)){
            uf.unite(xi,yi);
            n--;
            ret += pqtop.first;
        }
    }
    cout << ret << endl;
}