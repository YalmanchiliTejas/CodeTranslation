#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define tpl(...) make_tuple(__VA_ARGS__)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
  os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
  os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<int N,class Tuple> void out(ostream&,const Tuple&) {}
template<int N,class Tuple,class,class ...Ts> void out(ostream &os,const Tuple &t) {
	if(N)os<<","; os<<get<N>(t); out<N+1,Tuple,Ts...>(os,t);
}
template<class ...Ts> ostream& operator<<(ostream &os, const tuple<Ts...> &t) {
  os<<"("; out<0,tuple<Ts...>,Ts...>(os,t); os<<")"; return os;
}
template<class T>void output(T *a, int n) {REP(i,n){if(i)cout<<",";cout<<a[i];}cout<<endl;}
template<class T>void output(T *a, int n,int m) { REP(i,n) output(a[i],m);}

template<class T>
struct Heap {
  struct Node {
    T val;
    Node *l, *r;
    Node(T val) : val(val),l(NULL),r(NULL) {}
  } *root;
  Heap() : root(NULL) {}
  void init() { root = NULL; }
  Node *meld(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;
    if (b->val < a->val) swap(a,b);
    a->r = meld(a->r, b);
    swap(a->l, a->r);
    return a;
  }
  T top() { return root->val; }
  void pop() { root = meld(root->l, root->r); }
  void push(T t) { root = meld(root, new Node(t)); }
  bool empty() { return root==NULL; }
};
struct Edge {
  int a,b,w;
  Edge(int a, int b, int w) : a(a),b(b),w(w) {}
  bool operator<(const Edge &rhs) const {
    return w < rhs.w;
  }
};
vector<pii> g[100000];
int visited[100000];
vector<int> tree[100000];

const int MAX_N = 200000*2;
pii dat[MAX_N * 2 - 1];
int rmq_n;
void rmq_init(int *v, int size) {
  for (rmq_n=1; rmq_n<size; rmq_n*=2);
  REP(i,2*rmq_n-1) dat[i]=pii(INF,-1);
  REP(i,size) {
    dat[rmq_n-1+i] = pii(v[i], i);
  }
  for (int i=rmq_n-2; i>=0; --i)
    dat[i] = min(dat[i*2+1], dat[i*2+2]);
}
pii query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return pii(INF,-1);
  if (a <= l && r <= b) return dat[k];
  return min(query(a, b, k*2+1, l, (l+r)/2),
             query(a, b, k*2+2, (l+r)/2, r));
}
int q(int a, int b) {
  return query(a, b, 0, 0, rmq_n).second;
}
const int MAX_V = 100000;

int vs[MAX_V*2-1];
int depth[MAX_V*2-1];
int id[MAX_V];

void dfs(int v, int p, int d, int &k) {
  id[v] = k;
  vs[k] = v;
  depth[k++] = d;
  FOR(it, tree[v]) {
    if (*it != p) {
      dfs(*it, v, d+1, k);
      vs[k] = v;
      depth[k++] = d;
    }
  }
}
void init(int V, int root) {
  int k = 0;
  dfs(root, -1, 0, k);
  rmq_init(depth, V*2-1);
}
int calclca(int u, int v) {
  if (id[u]>id[v]) swap(u,v);
  return vs[q(id[u],id[v]+1)];
}

map<pii,int> ans;
Heap<Edge> hp[100000];

struct P {
  int v,p,t,i;
};
void solve(int vv, int pp) {
  stack<P> S;
  S.push(P({vv,pp,0,0}));
  while(!S.empty()) {
    int v = S.top().v;
    int p = S.top().p;
    int t = S.top().t;
    int I = S.top().i;
    // cout << tpl(v,p,t,I) << endl;
    S.pop();
    if (t == 0) {
      hp[v].init();
      bool flag = 0;
      for (int i=0; i<(int)tree[v].size(); ++i) {
        int z = tree[v][i];
        if (z == p) continue;
        S.push(P({v,p,1,i}));
        S.push(P({z,v,0,0}));
        flag = 1;
        break;
      }
      if (!flag) {
        S.push(P({v,p,2,0}));
      }
    } else if (t == 1) {
      int z = tree[v][I];
      int tmp = -1;
      while(!hp[z].empty()) {
        Edge e = hp[z].top();
        int lca = calclca(e.b,z);
        if (lca == z) {
          hp[z].pop();
          continue;
        }
        tmp = e.w;
        break;
      }
      ans[pii(v,z)] = tmp;
      ans[pii(z,v)] = tmp;
      hp[v].root = hp[v].meld(hp[v].root, hp[z].root);
      bool flag = 0;
      for (int i=I+1; i<(int)tree[v].size(); ++i) {
        int z = tree[v][i];
        if (z == p) continue;
        S.push(P({v,p,1,i}));
        S.push(P({z,v,0,0}));
        flag = 1;
        break;        
      }
      if (!flag) {
        S.push(P({v,p,2,0}));
      }      
    } else {
      FOR(it, g[v]) {
        if (it->first == p || ans.count(pii(v,it->first))) continue;
        hp[v].push(Edge(v,it->first,it->second));
      }
    }
  }
}

int a[200000];
int b[200000];
int w[200000];

int main() {
  int n,m;
  while(cin>>n>>m) {
    REP(i,n)g[i].clear();
    REP(i,m) {
      cin >> a[i] >> b[i] >> w[i];
      a[i]--;b[i]--;
      g[a[i]].push_back(pii(b[i],w[i]));
      g[b[i]].push_back(pii(a[i],w[i]));
    }
    Heap<Edge> Q;
    Q.push(Edge(-1,0,0));
    vector<Edge> edges;
    ll cost = 0;
    REP(i,n)visited[i]=0;
    while(!Q.empty()) {
      Edge e = Q.top(); Q.pop();
      if (visited[e.b]) continue;
      cost += e.w;
      edges.push_back(Edge(e));
      visited[e.b] = 1;
      FOR(it, g[e.b]) {
        if (!visited[it->first]) {
          Q.push(Edge(e.b,it->first,it->second));
        }
      }
    }
    if ((int)edges.size() < n) {
      REP(i,m) {
        puts("-1");
      }
      continue;
    }
    REP(i,n) tree[i].clear();
    FOR(it, edges) {
      if (it->a == -1) {
        continue;
      }
      tree[it->a].push_back(it->b);
      tree[it->b].push_back(it->a);
      // cout << it->a << " " << it->b << " " << it->w << endl;
    }
    init(n,0);
    ans.clear();
    solve(0,-1);
    REP(i,m) {
      if (ans.count(pii(a[i],b[i]))) {
        int r = ans[pii(a[i],b[i])];
        if (r == -1) {
          puts("-1");
        } else {
          printf("%lld\n", cost-w[i]+r);
        }
      } else {
        printf("%lld\n", cost);
      }
    }
  }
}