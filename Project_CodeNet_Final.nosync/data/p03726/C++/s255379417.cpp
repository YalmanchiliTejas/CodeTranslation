#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 100000 + 10;

int n, h[maxn], cnt, flag = 0;
struct enode{
  int v, n;
  enode() {}
  enode(int _v, int _n):v(_v), n(_n) {}
}e[maxn << 1];

inline void addedge(int u, int v) { cnt ++; e[cnt] = enode(v,h[u]); h[u] = cnt; }

int sum[maxn], a[maxn], sz[maxn];

void dfs1(int u, int fa) {
  sum[u] = 0;
  sz[u] = 1;
  a[u] = 0;
  int bo = 0;
  for(int i = h[u];~ i;i = e[i].n) {
    int v = e[i].v;
    if(v == fa) continue;
    dfs1(v,u);
    sz[u] += sz[v];
    bo = 1;
    if(a[v]) sum[u] ++;
  }
  if(!bo) a[u] = 1;
  else if(sum[u] > 1) {
  	a[u] = 1;
  	flag = 1;
  }
  else if(sum[u] == 0) {
    a[u] = 1;
  }
}

void dfs2(int u, int fa) {
  if(sum[u] > 1) {
  	flag = 1; 
//  	cout << u << endl;
  }
  for(int i = h[u], tmp, now;~ i;i = e[i].n) {
    int v = e[i].v;
    if(v == fa) continue;
    if(a[v]) tmp = sum[u] - 1;
    else tmp = sum[u];
    if(sz[1] - sz[v] == 1) sum[v] ++;
    else {
	  if(tmp > 1 || tmp == 0) sum[v] ++;
    }
    dfs2(v,u);
  }
}

int main() {
  scanf("%d", &n); cnt = 0;
  memset(h,-1,sizeof(h));
  for(int i = 1;i < n;i ++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u,v);
    addedge(v,u);
  }
  dfs1(1,0);
  dfs2(1,0);
  if(!flag) puts("Second");
  else puts("First");
  return 0;
}