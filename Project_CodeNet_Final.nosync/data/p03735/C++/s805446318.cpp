#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<queue>
#include<ctime>
#include<vector>
using namespace std;
inline int rd(){
  register char ch=getchar();
  register bool flag=false;
  register int res=0;
  while(ch<'0'||ch>'9'){flag=(ch=='-');ch=getchar();}
  while(ch>='0'&&ch<='9'){
    res=(res<<3)+(res<<1)+ch-'0';ch=getchar();}
  if(flag)res=-res;
  return res;
}
#define int long long
#define N 200010
#define INF 1000000000000000000LL
int n;
struct data{
  int a,b;
  inline void read(){
    a=rd();b=rd();
    if(a>b)swap(a,b);
  }
}dat[N];
inline int solve1(){
  int i,j,ma=dat[1].a,na=dat[1].a,mb=dat[1].b,nb=dat[1].b;
  for(i=1;i<=n;i++)
    ma=max(ma,dat[i].a),na=min(na,dat[i].a),
      mb=max(mb,dat[i].b),nb=min(nb,dat[i].b);
  // printf("solve1 %lld\n",(ma-na)*(mb-nb));
  return (ma-na)*(mb-nb);
}
bool cmp(const data &x,const data &y){
  return x.a<y.a;
}
int mb[N],na[N];
inline int solve2(){
  sort(dat+1,dat+n+1,cmp);
  /*int i,j,ha=dat[1].b,hb=dat[1].b;
  for(i=1;i<=n;i++)mb[i]=max(mb[i-1],dat[i].b);
  for(na[n+1]=na[n]=dat[n].a,i=n-1;i>=1;i--)na[i]=max(na[i+1],dat[i].a);
  for(i=1;i<=n;i++)
    ha=max(ha,dat[i].b),hb=min(hb,dat[i].b);

  int mn=INF,res=INF,sum=ha-hb;
  for(i=2;i<=n;i++){
    mn=min(mn,dat[i-1].b);//if(mn<=dat[i].a)break;//not allow
    if((max(mb[i-1],dat[n].a)-min(mn,dat[i].a))*(ha-dat[1].a)==0)continue;
    else
      res=min(res,(max(mb[i-1],dat[n].a)-min(mn,dat[i].a))*(ha-dat[1].a));}
  *///for(i=1;i<=n;i++)printf("[%lld %lld %lld]\n",dat[i].a,dat[i].b,mb[i]);
  //printf("solve2 %lld %lld[%lld %lld]\n",res,sum,ha,dat[1].a);
  int res=INF,i,j,pre,x1,x2,y1=0,y2=1e9;
  for(i=1;i<=n;i++)y1=max(y1,dat[i].b),y2=min(y2,dat[i].b);y2=dat[1].a;
  x1=max(dat[n].a,pre=dat[1].b);x2=dat[1].a;res=min(res,(y1-y2)*(x1-x2));
  // printf("ans=%lld %lld %lld %lld %lld %lld\n",res,x1,x2,y1,y2,pre);
  //printf("[%lld %lld %lld %lld]\n",x1,x2,y1,y2);
  for(i=2;i<n;i++){
    if((x2=dat[i].a)>pre)break;
    //printf("upd %lld\n",(y1-y2)*(x1-x2));  
  res=min(res,(y1-y2)*(x1-x2));
    x1=max(x1,dat[i].b);pre=min(pre,dat[i].b);
  }x2=pre;
  res=min(res,(y1-y2)*(x1-x2));
  //printf("%lld %lld %lld %lld\n",y1,y2,x1,x2);
  return res;
}
void work(){
  n=rd();
  int i,j;
  for(i=1;i<=n;i++)
    dat[i].read();
  printf("%lld\n",min(solve1(),solve2()));
}
#undef int 
int main(){
  work();
  return 0;
}
