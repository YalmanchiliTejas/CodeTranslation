#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100001;
const ll mod = 1e9+7;
int n, tot;
struct coo
{
    int x, y;
    int id;
}c[maxn];
bool cmp1(coo a, coo b){
  return a.x < b.x;
}
bool cmp2(coo a, coo b){
  return a.y < b.y;
}
int dx[maxn],dy[maxn];
struct Edge{
  int u, v;
  int cost;
}e[maxn];
bool cmp(Edge a, Edge b){
  return a.cost < b.cost;
}
int p[maxn];
int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  scanf("%d", &n);
  for(int i = 0; i <= n; i++) p[i] = i;
  for(int i = 1; i <= n; i++){
    scanf("%d%d", &dx[i], &dy[i]);
  }
  for(int i = 1; i <= n; i++)
  {
    c[i].x = dx[i]; c[i].y = dy[i];c[i].id = i;
  }
  sort(c+1,c+1+n,cmp1);
  for(int i = 1; i < n; i++){
    e[tot].u = c[i].id;
    e[tot].v = c[i+1].id;
    e[tot].cost = c[i+1].x - c[i].x;
    tot++;
  }
  sort(c+1,c+1+n,cmp2);
  for(int i = 1; i < n; i++){
    e[tot].u = c[i].id;
    e[tot].v = c[i+1].id;
    e[tot].cost = c[i+1].y - c[i].y;
    tot++;
  }
  sort(e,e+tot,cmp);
  ll ans = 0;
  int cnt = 0;
  for(int i = 0; i < tot; i++){
    int f = find(e[i].u);
    int t = find(e[i].v);
    if(f!=t){ans+=e[i].cost;p[p[e[i].u]] = p[e[i].v];cnt++;}
    if(cnt == n-1)break;
  }
  printf("%lld\n", ans);
  return 0;
}

