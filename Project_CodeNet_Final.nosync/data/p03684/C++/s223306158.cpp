#include<bits/stdc++.h>

using namespace std;

constexpr int N = 100005;

struct Edege{
  int u, v, w;
  bool operator < (const Edege &b) const{
    return w < b.w;
  }
};

struct Node{
  int id, x;
  bool operator < (const Node &b) const {
    return x < b.x;
  }
};

int fa[N], cnt;
Node a[N], b[N];
Edege e[N * 3];

void add(int u, int v, int w){
  e[cnt].u = u;
  e[cnt].v = v;
  e[cnt++].w = w;
}

int findFa(int u){
  if(fa[u] != u){
    fa[u] = findFa(fa[u]);
  }
  return fa[u];
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    fa[i] = i;
  }
  cnt = 1;
  for(int i = 1; i <= n; ++i){
    a[i].id = b[i].id = i;
    scanf("%d%d", &a[i].x, &b[i].x);
  }
  sort(a + 1, a + n + 1);
  for(int i = 2; i <= n; ++i){
    add(a[i].id, a[i - 1].id, a[i].x - a[i - 1].x);
  }
  sort(b + 1, b + n + 1);
  for(int i = 2; i <= n; ++i){
    add(b[i].id, b[i - 1].id, b[i].x - b[i - 1].x);
  }
  sort(e + 1, e + cnt + 1); 
  long long tempAns = 0;
  for(int i = 1; i < cnt; ++i){
    int u = e[i].u, v = e[i].v, w = e[i].w;
    u = findFa(u);
    v = findFa(v);
    if(u != v){
      tempAns += w;
      fa[v] = u;
    }
  }
  cout << tempAns << endl;
  return 0;
}
