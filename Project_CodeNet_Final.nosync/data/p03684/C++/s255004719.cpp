#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>bool chmin(T&a,const T&b){return a>b?(a=b,1):0;}
template<class T>bool chmax(T&a,const T&b){return a<b?(a=b,1):0;}


int nextInt() { int x; scanf("%d", &x); return x;}

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool link(int x, int y) { //新たな併合を行うとtrue
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  int root(int x) { // 代表元を返す
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) { // 要素xが含まれる集合の大きさ
    return -data[root(x)];
  }
  bool same(int x, int y) { // 同じ集合ならtrue
    return root(x) == root(y);
  }
  int num() { // 異なる集合の数
    int res = 0;
    REP(i, data.size()) res += root(i) == i;
    return res;
  }
};

struct Edge {
  int a, b, w;
};

const int MAX_N = 100000 + 10;
struct P {
  int id, x, y;
};
P p[MAX_N];

int main2() {
  int N = nextInt();
  REP(i, N) {
    p[i].id = i;
    p[i].x = nextInt();
    p[i].y = nextInt();
  }
  
  vector<Edge> es;
  sort(p, p + N, [](const P& a, const P& b) -> bool {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
  });
  for (int i = 0; i + 1 < N; i++) {
    es.push_back( (Edge){p[i].id, p[i+1].id, p[i+1].x - p[i].x } );
  }
  sort(p, p + N, [](const P& a, const P& b) -> bool {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
  });
  for (int i = 0; i + 1 < N; i++) {
    es.emplace_back( (Edge){p[i].id, p[i+1].id, p[i+1].y - p[i].y} );
  }

  sort(es.begin(), es.end(), [](const Edge& a, const Edge& b) -> bool {
    return a.w < b.w;
  });
  UnionFind uf(N);

  ll ans = 0;
  for (Edge e : es) {
    if (!uf.same(e.a, e.b)) {
      uf.link(e.a, e.b);
      ans += e.w;
    }
  }
  cout << ans << endl;

  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws) main2();
  return 0;
}

