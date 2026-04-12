#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}


template<typename Data, typename T>
struct ReRooting{
  struct Node{
    Int to,rev;
    Data data;
    Node(Int to,Int rev,Data data):to(to),rev(rev),data(data){}
  };

  using F1 = function<T(T, T)>;
  using F2 = function<T(T, Data)>;

  vector<vector<Node> > G;
  vector<vector<T> > ld,rd;
  vector<Int> lp,rp;

  const F1 f1;
  const F2 f2;
  const T id;

  ReRooting(Int n,const F1 f1,const F2 f2,const T &id):
    G(n),ld(n),rd(n),lp(n),rp(n),f1(f1),f2(f2),id(id){}

  void add_edge(Int u,Int v,Data d){
    G[u].emplace_back(v,(Int)G[v].size(),d);
    G[v].emplace_back(u,(Int)G[u].size()-1,d);
  }

  // p: idx for edge (not vertex)
  T dfs(Int v,Int p){
    while(lp[v]!=p&&lp[v]<(Int)G[v].size()){
      auto &e=G[v][lp[v]];
      ld[v][lp[v]+1]=f1(ld[v][lp[v]],f2(dfs(e.to,e.rev),e.data));
      lp[v]++;
    }
    while(rp[v]!=p&&rp[v]>=0){
      auto &e=G[v][rp[v]];
      rd[v][rp[v]]=f1(rd[v][rp[v]+1],f2(dfs(e.to,e.rev),e.data));
      rp[v]--;
    }
    if(p<0) return rd[v][0];
    return f1(ld[v][p],rd[v][p+1]);
  }

  vector<T> build(){
    for(Int i=0;i<(Int)G.size();i++){
      ld[i].assign((Int)G[i].size()+1,id);
      rd[i].assign((Int)G[i].size()+1,id);
      lp[i]=0;
      rp[i]=(Int)G[i].size()-1;
    }
    vector<T> res;
    for(Int i=0;i<(Int)G.size();i++){
      res.emplace_back(dfs(i,-1));
    }
    return res;
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  struct T{
    Int a,b,c;
    T(Int a,Int b,Int c):a(a),b(b),c(c){}
  };

  const Int INF = 1e9;
  auto f1=
    [&](T x,T y){
      vector<Int> vs({x.a,x.b,x.c,y.a,y.b,y.c});
      sort(vs.rbegin(),vs.rend());
      return T(vs[0],vs[1],vs[2]);
    };
  auto f2=
    [&](T x,Int y){
      chmax(x.a,0);
      x.a+=y;
      x.b=-INF;
      x.c=-INF;
      return x;
    };

  Int n;
  cin>>n;
  if(n==1) drop(1);

  ReRooting<Int, T> G(n,f1,f2,T(-INF,-INF,-INF));
  for(Int i=1;i<n;i++){
    Int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v,1);
  }
  auto res=G.build();

  string ans(n+1,'1');

  for(Int i=0;i<n;i++){
    if(G.G[i].size()<3) continue;
    T v=res[i];
    assert(v.a>=v.b);
    assert(v.b>=v.c);
    assert(v.c>=1);
    // cout<<v.a<<" "<<v.b<<" "<<v.c<<endl;
    ans[v.a+min({v.a-1,v.b,v.c})]='0';
  }

  for(Int i=n-1;i>=0;i--)
    if(ans[i+1]=='0') ans[i]='0';

  ans[1]='1';
  ans[2]='1';
  cout<<ans.substr(1)<<endl;
  return 0;
}

