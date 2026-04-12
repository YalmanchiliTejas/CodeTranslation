#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define SZ(a) int((a).size())
#define _REP(_1,_2,_3,_4,name,...) name
#define _REP4(i,b,e,s) for(decltype(e) _b=(b),_e=(e),i=_b+(0<(s)?0:(s));(0<(s)?i<_e:_e<=i);i+=(s))
#define _REP3(i,b,e) for(decltype(e) _b=(b),_e=(e),i=(_b<_e?_b:_b-1);(_b<_e?i<_e:_e<=i);(_b<_e?i++:i--))
#define _REP2(i,n) for(decltype(n) i=0,_n=(n);i<_n;i++)
#define _REP1(n) for(decltype(n) _i=0,_n=(n);_i<_n;_i++)
#define REP(...) _REP(__VA_ARGS__,_REP4,_REP3,_REP2,_REP1)(__VA_ARGS__)
#define FOR(it,c) for(auto&& it=begin(c);it!=end(c);it++)
#define ROF(it,c) for(auto&& it=rbegin(c);it!=rend(c);it++)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define INT(n) int n;scanf("%d",&n)
#define MSET(arr,val)  memset(arr,val,sizeof(arr))

int main(){
  INT(n);
  vector<tuple<int, int, int>> xy, yx;
  REP(i, n){
    INT(x); INT(y);
    xy.PB(MT(x, y, i));
    yx.PB(MT(y, x, i));
  }
  sort(xy.begin(), xy.end());
  sort(yx.begin(), yx.end());
  map<int, vector<pair<int, int>>> gr;
  int u, v, c;
  REP(i, n - 1){
    u = get<2>(xy[i]);
    v = get<2>(xy[i + 1]);
    c = min(abs(get<0>(xy[i + 1]) - get<0>(xy[i])), abs(get<1>(xy[i + 1]) - get<1>(xy[i])));
    gr[u].PB(MP(-c, v));
    gr[v].PB(MP(-c, u));
    u = get<2>(yx[i]);
    v = get<2>(yx[i + 1]);
    c = min(abs(get<0>(yx[i + 1]) - get<0>(yx[i])), abs(get<1>(yx[i + 1]) - get<1>(yx[i])));
    gr[u].PB(MP(-c, v));
    gr[v].PB(MP(-c, u));
  }
  bool added[n + 1]; MSET(added, false);
  LL ans = 0;
  priority_queue<pair<int, int>> pq;
  pq.push(MP(0, 0));
  while (0 < SZ(pq)){
    c = pq.top().first;
    u = pq.top().second;
    pq.pop();
    if (!added[u]){
      added[u] = true;
      ans -= c;
      FOR(it, gr[u]){
        pq.push(*it);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}