#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16

struct UnionFind{
  vector<int> v;
  UnionFind(int n) : v(n, -1) {}
  void init(){ for(int i = 0;i < v.size();i++)v[i]=-1; }
  int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (-v[x] < -v[y]) swap(x, y);
    v[x] += v[y]; v[y] = x;
    return true;
  }
  bool root(int x) { return v[x] < 0; }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -v[find(x)]; }
};

struct edge{
  int u,v,c,idx;
};

bool operator<(const edge& a,const edge& b){
  return a.c < b.c;
}

int n,m;
vector<edge> es;
vector<edge> ses;
vector<P> g[100010];
ll mstw;
ll res[200010];
bool used[200010];
int qnum;
vector<priority_queue<int,vector<int>,function<bool(int,int)> > > que;
vector<int> ord;
int qi[100010],par[100010];
vector<int> arg1,arg2,arg3;

void dfs(int v,int pre,int pe){
  vector<int> qidx;
  for(P e : g[v]){
    if(e.fi==pre||!used[e.se])continue;
    qidx.push_back(qi[e.fi]);
  }

  int crtqidx=-1;
  if(qidx.size()>0){
    sort(all(qidx),[=](const int& a,const int& b){ return que[a].size() > que[b].size(); });
    crtqidx=qidx[0];
    for(int i : qidx){
      if(crtqidx==i)continue;
      while(que[i].size()){
        que[crtqidx].push(que[i].top());
        que[i].pop();
      }
    }
  }else{ // leaf
    que.push_back(priority_queue<int,vector<int>,function<bool(int,int)> >([=](int a,int b){if(es[a].c!=es[b].c){return es[a].c > es[b].c;}else{return a < b;}}));
    crtqidx=qnum++;
  }

  for(P e : g[v]){
    if(e.fi==pre||used[e.se])continue;
    que[crtqidx].push(e.se);
  }

  while(que[crtqidx].size()){
    int ei=que[crtqidx].top(); que[crtqidx].pop();
    if(que[crtqidx].size()==0||que[crtqidx].top()!=ei){
      que[crtqidx].push(ei);
      break;
    }
    que[crtqidx].pop();
  }

  if(pe!=-1){
    if(que[crtqidx].size()>0) res[pe]=mstw-es[pe].c+es[que[crtqidx].top()].c;
    else res[pe]=-1;
  }

  qi[v]=crtqidx;
}

int main(){
  scanf("%d%d",&n,&m);
  rep(i,m){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a--;b--;
    es.push_back((edge){a,b,c,(int)i});
    ses.push_back((edge){a,b,c,(int)i});
  }
  sort(all(ses));
  UnionFind uf(n);
  rep(i,m){
    g[ses[i].u].push_back(P(ses[i].v,ses[i].idx));
    g[ses[i].v].push_back(P(ses[i].u,ses[i].idx));
    if(uf.same(ses[i].u,ses[i].v))continue;
    uf.unite(ses[i].u,ses[i].v);
    used[ses[i].idx]=true;
    mstw+=ses[i].c;
  }

  if(uf.size(0)<n){
    rep(i,m)printf("-1\n");
    return 0;
  }

  queue<int> que;
  que.push(0);
  par[0]=-1;
  while(que.size()){
    int v=que.front(); que.pop();
    for(P e : g[v]){
      if(e.fi==par[v]||!used[e.se])continue;
      arg1.push_back(e.fi); arg2.push_back(v); arg3.push_back(e.se);
      par[e.fi]=v;
      que.push(e.fi);
    }
  }

  rep(i,n-1){
    dfs(arg1[n-2-i],arg2[n-2-i],arg3[n-2-i]);
  }

  rep(i,m){
    if(used[i])printf("%lld\n", res[i]);
    else printf("%lld\n", mstw);
  }

  return 0;
}

