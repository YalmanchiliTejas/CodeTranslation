#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr8,pr7,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
#define prArr(a) {cerr<<(#a)<<"={";int i=0;for(auto t:(a))cerr<<(i++?", ":"")<<t;cerr<<"}"<<endl;}
using namespace std;
using Int = long long;
using _int = int;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<60)+1e9; // ~ 1.15 * 1e18
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
template<class T1, class T2> ostream& operator<<(ostream& o,pair<T1,T2> p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T1, class T2, class T3> ostream& operator<<(ostream& o,tuple<T1,T2,T3> t){
  return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class T1, class T2> istream& operator>>(istream& i,pair<T1,T2> &p){return i>>p.first>>p.second;}
template<class T> ostream& operator<<(ostream& o,vector<T> a){Int i=0;for(T t:a)o<<(i++?" ":"")<<t;return o;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(T &t:a)i>>t;return i;}

class Dinic{
public:
  
  struct edge{
    int to,cap,rev;
    edge(){};
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){};
  };

  int V;
  vector<vector<edge> > G; //グラフの隣接リスト表現
  vector<int> level;       //sからの距離
  vector<int> iter;        //どこまで調べ終わったか
  int INF;
  
  Dinic():V(-1){};
  Dinic(int V,int INF=1e9):V(V),G(V),level(V),iter(V),INF(INF){}

  //fromからtoへ向かう容量capの辺をグラフに追加。
  void add_edge(int from,int to,int cap){ //有向
    assert(from < V && to < V);
    G[from].push_back(edge(to,cap,G[to].size()));
    G[to].push_back(edge(from,0,G[from].size()-1));
  }
  
  void add_edge2(int from,int to,int cap){ //双方向
    assert(from < V && to < V);
    G[from].push_back(edge(to,cap,G[to].size()));
    G[to].push_back(edge(from,cap,G[from].size()-1));
  }

  //sからの最短距離をBFSで計算する
  void bfs(int s){
    level.clear(); level.resize(V,-1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
      int v = que.front(); que.pop();
      for(edge &e : G[v])
        if(e.cap > 0 && level[e.to] < 0){
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
    }
  }

  //増加パスをDFSで探す。
  int dfs(int v,int t,int f){
    if(v==t) return f;
    for(int &i= iter[v]; i<(int)G[v].size(); i++){
      edge &e = G[v][i];
      if(e.cap > 0 && level[v] < level[e.to]){
        int d = dfs(e.to, t, min(f, e.cap));
        if(d > 0){
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  //sからtへの最大流を求める
  int max_flow(int s,int t){
    assert(V >= 0);
    int flow=0;
    for(;;){
      bfs(s);
      if(level[t] < 0) return flow;
      iter.clear();iter.resize(V,0);
      int f;
      while((f=dfs(s ,t ,INF)) > 0 ) flow += f;
    }
  }
};

int solve(int h, int w, vector<string> mp){
  auto getIdx = [&](int y,int x){return y * w + x;};
  
  Dinic dinic(h * w * 2);
  int ofset = h * w;
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      dinic.add_edge(getIdx(i, j), getIdx(i, j) + ofset, 1);

      if(mp[i][j] == '#') continue;
      if(i + 1 < h && mp[i+1][j] != '#') {
	dinic.add_edge(getIdx(i, j) + ofset, getIdx(i+1, j), 1);
	dinic.add_edge(getIdx(i+1, j) + ofset, getIdx(i, j), 1);
      }
      if(j + 1 < w && mp[i][j+1] != '#') {
	dinic.add_edge(getIdx(i, j) + ofset, getIdx(i, j+1), 1);
	dinic.add_edge(getIdx(i, j+1) + ofset, getIdx(i, j), 1);
      }
    }
  }

  auto dinic2 = dinic;
  int a = dinic.max_flow(getIdx(0, 0) + ofset, getIdx(h-1, w-1));
  int b = dinic2.max_flow(getIdx(0, w-1) + ofset, getIdx(h-1, 0));
  return a >= 2 && b >= 2;
}

signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);
  
  while(1){
    int h, w;
    cin>>h>>w;
    if(h == 0 && w == 0) break;
    vector<string> mp(h);
    cin>>mp;
    int ans = solve(h, w, mp);
    cout<<(ans? "YES":"NO")<<endl;
  
  }

  return 0;
}

