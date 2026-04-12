#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define lim 100001
using namespace std;
struct point
{
	int x,y,id;
} c[lim];
struct edge
{
	int u,v,cost;
} e[2*lim];
bool cmp1(point a,point b)
{
	return a.x < b.x;
}
bool cmp2(point a,point b)
{
	return a.y < b.y;
}
bool cmp(edge a,edge b)
{
	return a.cost < b.cost;
}
int p[lim];
int dx[lim],dy[lim];
int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
int n,tot;
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  cin >> n;
  for(int i = 0; i <= n; i++) p[i] = i;
  for(int i = 1; i <= n; i++){
   cin >> dx[i] >> dy[i];
  }
  for(int i = 1; i <= n; i++)
  {
    c[i].x = dx[i]; c[i].y = dy[i];c[i].id = i;
  }
  sort(c+1,c+1+n,cmp1);
  for(int i = 2; i <= n; i++){
    e[tot].u = c[i].id;
    e[tot].v = c[i-1].id;
    e[tot].cost = c[i].x - c[i-1].x;
    tot++;
  }
  sort(c+1,c+1+n,cmp2);
  for(int i = 2; i <= n; i++){
    e[tot].u = c[i].id;
    e[tot].v = c[i-1].id;
    e[tot].cost = c[i].y - c[i-1].y;
    tot++;
  }
  sort(e,e+tot,cmp);
  int ans = 0;
  int cnt = 0;
  for(int i = 0; i < tot; i++){
    int f = find(e[i].u);
    int t = find(e[i].v);
    if(f!=t){ans+=e[i].cost;p[f] = t;cnt++;}
    if(cnt == n-1) break;
  }
  cout << ans;
  return 0;
}