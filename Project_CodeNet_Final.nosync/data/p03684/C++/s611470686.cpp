#include <bits/stdc++.h>
using namespace std;

#define _p(...) (void)printf(__VA_ARGS__)
#define forr(x,arr) for(auto&& x:arr)
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) _rep3(i,0,n)
#define _rep3(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2,)(__VA_ARGS__)
#define _rrep2(i,n) _rrep3(i,0,n)
#define _rrep3(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL<<(n))
#define sz(x) ((int)(x).size())
#define TEN(n) ((ll)(1e##n))
#define fst first
#define snd second

string DBG_DLM(int &i){return(i++==0?"":", ");}
#define DBG_B(exp){int i=0;os<<"{";{exp;}os<<"}";return os;}
template<class T>ostream&operator<<(ostream&os,vector<T>v);
template<class T>ostream&operator<<(ostream&os,set<T>v);
template<class T>ostream&operator<<(ostream&os,queue<T>q);
template<class T>ostream&operator<<(ostream&os,priority_queue<T>q);
template<class T,class K>ostream&operator<<(ostream&os,pair<T,K>p);
template<class T,class K>ostream&operator<<(ostream&os,map<T,K>mp);
template<class T,class K>ostream&operator<<(ostream&os,unordered_map<T,K>mp);
template<int I,class TPL>void DBG(ostream&os,TPL t){}
template<int I,class TPL,class H,class...Ts>void DBG(ostream&os,TPL t){os<<(I==0?"":", ")<<get<I>(t);DBG<I+1,TPL,Ts...>(os,t);}
template<class T,class K>void DBG(ostream&os,pair<T,K>p,string delim){os<<"("<<p.first<<delim<<p.second<<")";}
template<class...Ts>ostream&operator<<(ostream&os,tuple<Ts...>t){os<<"(";DBG<0,tuple<Ts...>,Ts...>(os,t);os<<")";return os;}
template<class T,class K>ostream&operator<<(ostream&os,pair<T,K>p){DBG(os,p,", ");return os;}
template<class T>ostream&operator<<(ostream&os,vector<T>v){DBG_B(forr(t,v){os<<DBG_DLM(i)<<t;});}
template<class T>ostream&operator<<(ostream&os,set<T>s){DBG_B(forr(t,s){os<<DBG_DLM(i)<<t;});}
template<class T>ostream&operator<<(ostream&os,queue<T>q){DBG_B(for(;q.size();q.pop()){os<<DBG_DLM(i)<<q.front();});}
template<class T>ostream&operator<<(ostream&os,priority_queue<T>q){DBG_B(for(;q.size();q.pop()){os<<DBG_DLM(i)<<q.top();});}
template<class T,class K>ostream&operator<<(ostream&os,map<T,K>m){DBG_B(forr(p,m){os<<DBG_DLM(i);DBG(os,p,"->");});}
template<class T,class K>ostream&operator<<(ostream&os,unordered_map<T,K>m){DBG_B(forr(p,m){os<<DBG_DLM(i);DBG(os,p,"->");});}
#define DBG_OVERLOAD(_1,_2,_3,_4,_5,_6,macro_name,...)macro_name
#define DBG_LINE(){char s[99];sprintf(s,"line:%3d | ",__LINE__);cerr<<s;}
#define DBG_OUTPUT(v){cerr<<(#v)<<"="<<(v);}
#define DBG1(v,...){DBG_OUTPUT(v);}
#define DBG2(v,...){DBG_OUTPUT(v);cerr<<", ";DBG1(__VA_ARGS__);}
#define DBG3(v,...){DBG_OUTPUT(v);cerr<<", ";DBG2(__VA_ARGS__);}
#define DBG4(v,...){DBG_OUTPUT(v);cerr<<", ";DBG3(__VA_ARGS__);}
#define DBG5(v,...){DBG_OUTPUT(v);cerr<<", ";DBG4(__VA_ARGS__);}
#define DBG6(v,...){DBG_OUTPUT(v);cerr<<", ";DBG5(__VA_ARGS__);}
#define DEBUG0(){DBG_LINE();cerr<<endl;}
#ifdef LOCAL
#define out(...){DBG_LINE();DBG_OVERLOAD(__VA_ARGS__,DBG6,DBG5,DBG4,DBG3,DBG2,DBG1)(__VA_ARGS__);cerr<<endl;}
#else
#define out(...)
#endif

using ll=long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pil=pair<int,ll>;using pli=pair<ll,int>;
using vs=vector<string>;using vvs=vector<vs>;using vvvs=vector<vvs>;
using vb=vector<bool>;using vvb=vector<vb>;using vvvb=vector<vvb>;
using vi=vector<int>;using vvi=vector<vi>;using vvvi=vector<vvi>;
using vl=vector<ll>;using vvl=vector<vl>;using vvvl=vector<vvl>;
using vd=vector<double>;using vvd=vector<vd>;using vvvd=vector<vvd>;
using vpii=vector<pii>;using vvpii=vector<vpii>;using vvvpii=vector<vvpii>;
template<class T>bool amax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>bool amin(T&a,const T&b){return a>b?a=b,1:0;}
ll ri(){ll l;cin>>l;return l;} string rs(){string s;cin>>s;return s;}

struct UnionFind {
  const int V; // 頂点数
  vector<int> par, rank, cnt; // 親の番号, 木の大きさ, 同じ親の頂点数
  UnionFind(int V) : V(V), par(V), rank(V), cnt(V) { init(); }

  // 初期化する
  void init() {
    for (int i = 0; i < V; i++) par[i] = i;
    fill(rank.begin(), rank.end(), 0);
    fill(cnt.begin(), cnt.end(), 1);
  }

  // 木の根を求める
  int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }

  // x と y の属する集合を併合
  // 併合前は違う集合だったら true を返す
  bool unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    cnt[y] = cnt[x] = cnt[x] + cnt[y];

    if (rank[x] < rank[y]) par[x] = y;
    else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
    return true;
  }

  // x と y が同じ集合に属するか否か
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // x と同じ集合にいる頂点数を返す
  int count(int x) {
    return cnt[find(x)];
  }
};

struct T {
  int x;
  int y;
  int idx;
};

void Main() {
  int n = ri();
  vector<T> towns(n);

  rep(i, n) {
    int x = ri();
    int y = ri();
    towns[i] = {x, y, i};
  }

  vector<pair<int, pii>> edges;

  sort(all(towns), [](const T &l, const T &r) {return l.x < r.x;});

  rep(i, 1, n) {
    int dx = towns[i].x - towns[i-1].x;
    int idx1 = towns[i].idx;
    int idx2 = towns[i-1].idx;

    edges.emplace_back(dx, make_pair(idx1, idx2));
  }

  sort(all(towns), [](const T &l, const T &r) {return l.y < r.y;});

  rep(i, 1, n) {
    int dy = towns[i].y - towns[i-1].y;
    int idx1 = towns[i].idx;
    int idx2 = towns[i-1].idx;

    edges.emplace_back(dy, make_pair(idx1, idx2));
  }

  sort(all(edges));

  ll ans = 0;

  UnionFind uf(n);
  forr(e, edges) {
    if (!uf.same(e.snd.fst, e.snd.snd)) {
      ans += e.fst;
      uf.unite(e.snd.fst, e.snd.snd);
    }
  }

  cout << ans << endl;
}

signed main() { cin.tie(nullptr); ios::sync_with_stdio(false); Main(); return 0; }
