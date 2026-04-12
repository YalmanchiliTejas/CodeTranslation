#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
#define INF 0x3f3f3f3f
#define memset(a,b) memset(a,b,sizeof(a))
const LL mod=1000000007;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=100005;
 
int n, fa[maxn], cnt;
 
struct edge{
   int u, v, cost;
   edge(int cu, int cv, int ccost){u=cu, v=cv, cost=ccost;}
   edge(){}
   bool operator<(const edge &cmp) const{
       return cost<cmp.cost;
   }
}E[maxn*4];
 
struct point{
   int x, y, id;
}P[maxn];;
 
bool cmpx(point c1, point c2){return c1.x<c2.x;}
 
bool cmpy(point c1, point c2){return c1.y<c2.y;}
 
int Find(int x){
   return x==fa[x]?x:fa[x]=Find(fa[x]);
}
 
LL Kruskal(){
   for(int i=0;i<=n;i++)fa[i]=i;
   sort(E, E+cnt);
   LL ans=0;
   for(int i=0;i<cnt;i++){
       int fu=Find(E[i].u);
       int fv=Find(E[i].v);
       if(fu!=fv){
           ans+=E[i].cost;
           fa[fu]=fv;
       }
   }
   return ans;
}
 
int main()
{
   while(~scanf("%d", &n)){
       for(int i=0;i<n;i++){
           scanf("%d%d", &P[i].x, &P[i].y);
           P[i].id=i;
       }
       cnt=0;
       sort(P, P+n, cmpx);
       for(int i=1;i<n;i++){
           E[cnt++]=edge(P[i-1].id, P[i].id, P[i].x-P[i-1].x);
       }
       sort(P, P+n, cmpy);
       for(int i=1;i<n;i++){
           E[cnt++]=edge(P[i-1].id, P[i].id, P[i].y-P[i-1].y);
       }
       printf("%lld\n", Kruskal());
   }
   return 0;
}