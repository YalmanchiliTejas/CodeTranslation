#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

typedef pair<int,int> Pi;
struct edge {int u, v; ll cost;};

vector<edge> es;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

// 計算量：O(ElogV)
ll kruskal(int V){

    sort(all(es), [&](const edge& e1,const edge& e2){
        return e1.cost < e2.cost;
    });

    UnionFind uf(V);

    ll res = 0;
    for(int i = 0; i < (int)es.size(); i++){
        edge e = es[i];
        if(!uf.issame(e.u,e.v)) {
            uf.merge(e.u,e.v);
            res += e.cost;
        }
    }
    return res;
}

int main(){
    int N;
    cin >> N;

    vector<pair<int,int>> X(N), Y(N);
    REP(i,N) {
        cin >> X[i].first >> Y[i].first;
        X[i].second = i;
        Y[i].second = i;
    }

    sort(all(X));
    REP(i, N - 1) es.push_back({X[i].second, X[i + 1].second, abs(X[i].first - X[i + 1].first)});

    sort(all(Y));
    REP(i, N - 1) es.push_back({Y[i].second, Y[i + 1].second, abs(Y[i].first - Y[i + 1].first)});

    cout << kruskal(N) << endl;;
}