#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;

// #define DEBUG 1

#ifdef DEBUG
#define NDEBUG
#include "cout11.h"
#endif
#undef NDEBUG
#include <cassert>

#ifndef INT_MAX
#define INT_MAX 0x7fffffff
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define foreqr(eqr,mm,v) for (auto eqr=mm.equal_range(v);eqr.first!=eqr.second;++eqr.first)
#define lower_index(s,v)  (int)(lower_bound(s.begin(),s.end(),v)-s.begin())
#define upper_index(s,v)  (int)(upper_bound(s.begin(),s.end(),v)-s.begin())


#define INTSPACE 11
char _buf[INTSPACE*1000000 + 3];

int loadint() {
    if (fgets(_buf, INTSPACE+3, stdin) == NULL) return -1;
    return atoi(_buf);
}
int loadvec(vector<int>& v, int N) {
    int bufsize = INTSPACE*N + 3;
    if (fgets(_buf, bufsize, stdin) == NULL) return -1;
    v.resize(N);

    int i=0;
    bool last = false;
    for (char *p=&_buf[0]; ;) {
        char *q = p;
        while (*q > ' ') ++q;
        if (*q == 0x0D || *q == 0x0A) last = true;
        *q = 0;
        v[i++] = atoi(p);
        if (last || i == N) break;
        p = q+1;
    }
    // assert(i <= N);
    return i;
}

class UnionFind {
  vector<int> data;
 public:
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

ll solve(int n, vector<int>&x, vector<int>&y) {
    assert(x.size() == n && y.size() == n);

    vector<ii> xx(n), yy(n);
    rep(i, n) {
        xx[i] = ii(x[i], i);
        yy[i] = ii(y[i], i);
    }
    sort(ALL(xx));
    sort(ALL(yy));

    UnionFind uf(n);

    priority_queue<pair<int,ii>> pq;
    rep(i, n-1) {
        pq.push(make_pair(-(xx[i+1].first - xx[i].first),
                          ii(xx[i].second, xx[i+1].second)));
        pq.push(make_pair(-(yy[i+1].first - yy[i].first),
                          ii(yy[i].second, yy[i+1].second)));
    }

    ll cost = 0;
    while (!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second.first, v = pq.top().second.second; pq.pop();
        if (uf.root(u) == uf.root(v)) continue;
        cost += d;
        uf.unionSet(u, v);
        if (uf.size(u) == n) break;
    }
    return cost;
}

int main(){
    int N = loadint();
    vector<int> tmp(2);

    vector<int> x(N), y(N);
    rep(i, N) {
        loadvec(tmp, 2);
        x[i]=tmp[0]; y[i]=tmp[1];
    }
    printf("%lld\n", solve(N, x, y));

    return 0;
}
