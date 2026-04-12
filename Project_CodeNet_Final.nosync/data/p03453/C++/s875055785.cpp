#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
typedef long double ld;
using namespace std;
///////////////////////////
#define INF 1000000000000000009
#define MAX_V 100001
typedef pair<ll, ll> p;
struct edge{ll to, cost;};
std::vector<vector<edge> > G(MAX_V);
std::vector<ll> pre(MAX_V,-1);
priority_queue<p, std::vector<p>, greater<p> > que; //class, inner, compair
std::vector<ll> d(MAX_V+1, INF);
std::vector<ll> ds(MAX_V, 0), dt(MAX_V, 0), DS(MAX_V, 0), DT(MAX_V, 0);
ll P = 1000000007;
void dijkstra(int start, int mode){
  d[start]=0;
  que.push(p(0, start));
  while(!que.empty()){
    p p_now=que.top(); que.pop();
    ll v = p_now.second;
    if(d[v]<p_now.first) continue;
    for(int i=0;i<G[v].size();i++){
      edge e = G[v][i];
      if(d[e.to]==d[v]+e.cost) (mode==1?ds[e.to]:dt[e.to]) = ((mode==1?ds[e.to]:dt[e.to]) +  (mode==1?ds[v]:dt[v]))%P;
      if(d[e.to]>d[v]+e.cost){
        (mode==1?ds[e.to]:dt[e.to]) = (mode==1?ds[v]:dt[v]);
        d[e.to]=d[v]+e.cost;
        pre[e.to] = v;
        que.push(p(d[e.to], e.to));
      }
    }
  }
}
ll pm(ll a, ll b){return (a - b + P)%P;}
ll pp(vector<ll> a){
  ll ret = 1;
  for(int i=0;i<a.size();i++) ret = (ret * a[i])%P;
  return ret;
}
/////////////////////////////////////////////
int main(int argc, char const *argv[]) {
  ll N, M, S, T, a, b, c, ans = 0;
  std::cin >> N >> M;
  std::cin >> S >> T;
  vvl eg = vv(0, 3, 0, ll);
  for(int i=0;i<M;i++){
    scanf("%lld %lld %lld", &a, &b, &c);
    eg.push_back(std::vector<ll> {a, b, c});
    eg.push_back(std::vector<ll> {b, a, c});
    G[a].push_back(edge{b, c});
    G[b].push_back(edge{a, c});
  }

  ds[S] = dt[T] = 1;
  dijkstra(S, 1);
  for(int i=1;i<=N;i++) DS[i] = d[i];
  for(int i=1;i<=N;i++) d[i] = INF;
  dijkstra(T, -1);
  for(int i=1;i<=N;i++) DT[i] = d[i];
  if(DS[T]==INF){
    std::cout << 0 << '\n';
    return 0;
  }
  ans = (ds[T]*ds[T])%P;
  for(int i=1;i<=N;i++){
    if(DS[T] == 2 * DS[i]){
      ans = pm(ans, pp(vector<ll> {ds[i], ds[i], dt[i], dt[i]}));
    }
  }
  for(int i=0;i<eg.size();i++){
    if(2*DS[eg[i][0]]<DS[T]&&2*DS[eg[i][1]]>DS[T]&&DS[eg[i][0]]+eg[i][2]+DT[eg[i][1]]==DS[T]){
      ans = pm(ans, pp(vector<ll> {ds[eg[i][0]], ds[eg[i][0]], dt[eg[i][1]], dt[eg[i][1]]}));
    }
  }
  std::cout << ans << '\n';
  return 0;
}
