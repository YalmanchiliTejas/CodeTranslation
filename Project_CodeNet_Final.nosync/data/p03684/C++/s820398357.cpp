#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=100005;
int ufs[maxn];
int find(int x){
  return x==ufs[x]?x:ufs[x]=find(ufs[x]);
}
bool link(int a,int b){
  if(find(a)==find(b))return false;
  else{
    ufs[find(a)]=find(b);return true;
  }
}
struct node{
  int x,y,num;
}P[maxn];
bool cmp1(const node &A,const node &B){
  return A.x<B.x;
}
bool cmp2(const node &A,const node &B){
  return A.y<B.y;
}
struct edge{
  int a,b,w;
  edge(){}
  edge(int _a,int _b,int _w){
    a=_a;b=_b;w=_w;
  }
  bool operator <(const edge &B)const{
    return w<B.w;
  }
}E[maxn<<1];int tot=0;
int main(){
  int n;scanf("%d",&n);
  for(int i=1;i<=n;++i){
    scanf("%d%d",&P[i].x,&P[i].y);P[i].num=i;
  }
  sort(P+1,P+n+1,cmp1);
  for(int i=1;i<n;++i){
    E[++tot]=edge(P[i].num,P[i+1].num,P[i+1].x-P[i].x);
  }
  sort(P+1,P+n+1,cmp2);
  for(int i=1;i<n;++i){
    E[++tot]=edge(P[i].num,P[i+1].num,P[i+1].y-P[i].y);
  }
  sort(E+1,E+tot+1);
  for(int i=1;i<=n;++i)ufs[i]=i;
  int ans=0;
  for(int i=1;i<=tot;++i){
    if(link(E[i].a,E[i].b))ans+=E[i].w;
  }
  printf("%d\n",ans);
  return 0;
}
