#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
static inline char GET(void)
{
  static char buf[1<<15],*s1=buf,*s2=buf;
  return s1==s2&&(s2=(s1=buf)+fread(buf,1,1<<15,stdin),s1==s2)?EOF:*s1++;
}
static inline void PUT(char c)
{
  static char buf[1<<15],*ptr=buf;
  if(ptr==buf+strlen(buf)||c==0){fwrite(buf,1,ptr-buf,stdout),ptr=buf;}*ptr++=c;
}
static inline int IN(void)
{
  int x=0,f=0,c=GET();while(c<48||c>57){f^=c==45,c=GET();}
  while(c>47&&c<58){x=x*10+c-48,c=GET();}return f?-x:x;
}
static inline void OUT(int a)
{
  if(a<0)PUT('-'),a=-a;
  int d[40],i=0;do{d[i++]=a%10;}while(a/=10);
  while(i--){PUT(d[i]+48);}PUT('\n');
}
static inline int Max(int x,int y){return x>y?x:y;}
static inline void AscRadix32(int *a,const int sz)
{
  int x,shift=0,elem[0400],temp[sz];
  while(shift<040)
  {
    int bucket[0400]={0};
    rep(i,sz){x=(a[i]>>shift)&0377;bucket[x]++;temp[i]=a[i];}
    elem[0]=0;rep(i,0377)elem[i+1]=elem[i]+bucket[i];
    rep(i,sz){x=(temp[i]>>shift)&0377;a[elem[x]]=temp[i];elem[x]++;}
    shift+=010;
  }
}
int work[10006][3],sz=0;
static inline void Add(int x,int y,int v){work[sz][0]=x;work[sz][1]=y;work[sz++][2]=v;}
int main(void)
{
  int N=IN(),A[3*N],dp[N][N],B[N],mx,extra=0;
  rep(i,3*N)A[i]=IN()-1;
  memset(B,-0x3f,sizeof(B));
  memset(dp,-0x3f,sizeof(dp));
  dp[A[0]][A[1]]=dp[A[1]][A[0]]=B[A[0]]=B[A[1]]=mx=0;
  rep(i,N-1)
  {
    int x[3]={A[3*i+2],A[3*i+3],A[3*i+4]};
    AscRadix32(x,3);
    if(x[2]==x[0]){extra++;continue;}
    if(x[0]==x[1])rep(j,N)Add(j,x[2],dp[j][x[0]]+1);
    if(x[1]==x[2])rep(j,N)Add(j,x[0],dp[j][x[1]]+1);
    rep(j,3)Add(x[j==0],x[j==2?1:2],dp[x[j]][x[j]]+1);
    rep(j,3)rep(k,j)Add(x[j],x[k],mx);
    rep(j,N)rep(k,3)Add(j,x[k],B[j]);
    rep(j,sz)if(dp[work[j][0]][work[j][1]]<work[j][2])
      dp[work[j][0]][work[j][1]]=dp[work[j][1]][work[j][0]]=work[j][2],
      B[work[j][0]]=Max(B[work[j][0]],work[j][2]),
      B[work[j][1]]=Max(B[work[j][1]],work[j][2]),mx=Max(mx,work[j][2]);
    sz=0;
  }
  return OUT(Max(mx,dp[A[3*N-1]][A[3*N-1]]+1)+extra),0;
}