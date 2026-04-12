#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
#include <bitset>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define GI(i) (scanf("%d",&i))
#define GLL(i) (scanf("%lld",&i))
#define GD(i)  (scanf("%lf",&i))
#define PB          push_back
#define MP          make_pair
#define MT          make_tuple
#define GET0(x)     (get<0>(x))
#define GET1(x)     (get<1>(x))
#define GET2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       (1LL<<60)
#define LLMIN       -(1LL<<60)
#define IMAX        (1<<30)
#define IMIN        -(1<<30)
typedef long long LL;
using namespace std;

template<int M, bool IsPrime = false>
class Modulo {
  using ll = long long;
  int n;
  static ll inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
  }
public:
  Modulo () : n(0) {;}
  Modulo (int m) : n(m) {
    if (n >= M) n %= M;
    else if (n < 0) n = (n % M + M) % M;
  }
  Modulo (ll m) {
    if (m >= M) m %= M;
    else if (m < 0) m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo &operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Modulo &operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Modulo &operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }
  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }
  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }
  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }
  Modulo operator^(int n) const {
    if (n == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
  Modulo operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
  Modulo operator/=(const Modulo &a) {
    return *this *= inv(ll(a), M);
  }
};

template<int M, bool IsPrime = false>
bool is_zero(Modulo<M, IsPrime> x) { return int(x) == 0; }
template<int M, bool IsPrime = false>
int abs(Modulo<M, IsPrime> x) { return int(x); }

const LL mod = 1e9+7;

// swがtrueなら逆数が返ってくる
template<int M = mod> Modulo<M, true> fact(int n, bool sw = true) {
  static vector<Modulo<M, true>> v1 = {1}, v2 = {1};
  if (n >= (int)v1.size()) {
    const int from = v1.size(), to = n + 1024;
    v1.reserve(to);
    v2.reserve(to);
    for (int i = from; i < to; ++i) {
      v1.push_back(v1.back() * Modulo<M, true>(i));
      v2.push_back(v2.back() / Modulo<M, true>(i));
    }
  }
  return sw ? v1[n] : v2[n];
}

template<int M = mod> Modulo<M, true> comb(int a, int b) {
  if (b < 0 || b > a) return 0;
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}

using Mod = Modulo<mod, true>;

struct Edge{
        int to;
        LL cost;
};
bool operator < (const Edge &e,const Edge &f){	return e.cost>f.cost;	};	//INVERSE!!
typedef vector<vector<Edge>> Graph;

void addEdge(Graph &g,int from,int to,LL cost){
    g[from].push_back((Edge){to,cost});
}

LL dijkstra(const Graph &G,vector<LL> &dist,int s,int g)
{
    dist = vector<LL>(G.size(),LLMAX);
    priority_queue<Edge> que;
    que.push(Edge{s,0});
    while(!que.empty()){
        Edge e=que.top();
        que.pop();
        if(e.cost<dist[e.to]){
            dist[e.to]=e.cost;
            for(int i=0;i<(int)G[e.to].size();i++)
                que.push(Edge{G[e.to][i].to,e.cost+G[e.to][i].cost});
        }
    }
    return dist[g];
}

int N,M,S,T;
Graph G;
LL distST;
vector<LL> distFromS;
vector<LL> distFromT;
Mod fromS[100000],fromT[100000];
int visitS[100000],visitT[100000];

Mod dfsS(int v){
    // printf("dfsS(%d)\n",v);
    if(v == S)
        fromS[S] = 1;
    else if(visitS[v])
        ;
    else{
        visitS[v] = 1;
        fromS[v] = 0;
        for(auto e : G[v])
            if(distFromT[v] + e.cost + distFromS[e.to] == distST){
                fromS[v] += dfsS(e.to);
            }
    }
    return fromS[v];
}

Mod dfsT(int v){
    if(v == T)
        fromT[T] = 1;
    else if(visitT[v])
        ;
    else{
        visitT[v] = 1;
        fromT[v] = 0;
        for(auto e : G[v])
            if(distFromS[v] + e.cost + distFromT[e.to] == distST){
                fromT[v] += dfsT(e.to);
            }
    }
    return fromT[v];
}

int main(void){
    GI(N);GI(M);GI(S);GI(T);S--;T--;
    G = Graph(N);
    REP(i,M){
        int u,v;
        LL d;
        GI(u);GI(v);GLL(d);u--;v--;
        addEdge(G,u,v,d);
        addEdge(G,v,u,d);
    }
    distST = dijkstra(G,distFromS,S,T);
    dijkstra(G,distFromT,T,S);
    dfsS(T);
    dfsT(S);
    Mod ans = fromS[T]*fromS[T];
    REP(i,N){
        if(2LL*distFromS[i] == distST && 2LL * distFromT[i] == distST){
            // printf("i=%d\n",i);
            Mod a = fromS[i] * fromT[i];
            ans -= a*a;
        }
        for(auto e : G[i]){
            if(distFromS[i] + e.cost + distFromT[e.to] == distST && 2LL*distFromS[i] < distST && distST < 2LL*distFromS[e.to]){
                ans -= (fromS[i])*(fromT[e.to])*(fromS[i])*(fromT[e.to]);
            }
        }
    }
    printf("%d\n",abs(ans));
    return 0;
}
