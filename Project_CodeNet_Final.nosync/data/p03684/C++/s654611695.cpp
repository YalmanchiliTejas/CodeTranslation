#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


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

struct P {
  int id, x, y;
};

struct E {
  int a, b, c;
};

int main2() {
  int N = nextInt();
  vector<P> ps;
  REP(i, N) {
    int x = nextInt();
    int y = nextInt();
    ps.push_back({i, x, y});
  }

  vector<E> es;

  sort(ALL(ps), [](const P& a, const P& b) -> bool {
    return a.x < b.x;
  });

  REP(i, N-1) {
    int c = min(
        abs(ps[i].x - ps[i+1].x),
        abs(ps[i].y - ps[i+1].y));
    es.push_back({ps[i].id, ps[i+1].id, c});
  }

  sort(ALL(ps), [](const P& a, const P& b) -> bool {
    return a.y < b.y;
  });
  REP(i, N-1) {
    int c = min(
        abs(ps[i].x - ps[i+1].x),
        abs(ps[i].y - ps[i+1].y));
    es.push_back({ps[i].id, ps[i+1].id, c});
  }
  sort(ALL(es), [](const E& a, const E& b) -> bool {
    return a.c < b.c;
  });

  UnionFind uf(N);
  ll ans = 0;
  REP(i, es.size()) {
    if (!uf.same(es[i].a , es[i].b)) {
      uf.link(es[i].a , es[i].b);
      ans += es[i].c;
    }
  }
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
