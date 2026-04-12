#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>
using namespace std;

#define MAX_N 100000+10
#define MAX_E 4*(100000+10)
int par[MAX_N];
int union_rank[MAX_N];

void init_union_find(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    union_rank[i] = 0;
  }
}

int find_union_find(int x){
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find_union_find(par[x]);
  }
}

void unite_union_find(int x, int y) {
  x = find_union_find(x);
  y = find_union_find(y);
  if ( x == y) return;

  if (union_rank[x] < union_rank[y] ) {
    par[x] = y;
  } else {
    par[y] = x;
    if (union_rank[x] == union_rank[y]) {
      union_rank[x]++;
    }
  }

}

bool same_union_find(int x, int y) {
  return find_union_find(x) == find_union_find(y);
}

struct edge{int u,v, cost;};

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}


edge es[MAX_E];
int V,E;

int kruskal() {
  sort(es, es+E, comp);
  init_union_find(V);
  int res=0;
  for(int i=0;i<E;++i) {
    edge e =es[i];
    if(!same_union_find(e.u,e.v)){
      unite_union_find(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}


typedef pair<int,int> city_data;

city_data x[MAX_N];
city_data y[MAX_N];

int main() {
  int N;
  scanf("%d", &N);
  for(int i=0;i<N;++i){
    scanf("%d%d", &x[i].first, &y[i].first);
    x[i].second = i;
    y[i].second = i;
  }

  V=N;

  sort(x, x+N);
  sort(y, y+N);

  int it=0;
  for(int i=0;i<N-1;++i){
    {
      int cost=abs(x[i].first - x[i+1].first);
      es[it].u=x[i].second;
      es[it].v=x[i+1].second;
      es[it].cost=cost;
      it++;
    }
    {
      int cost=abs(y[i].first - y[i+1].first);
      es[it].u=y[i].second;
      es[it].v=y[i+1].second;
      es[it].cost=cost;
      it++;
    }
  }
  E=it;


  printf("%d",kruskal());
 
  
  return 0;
}