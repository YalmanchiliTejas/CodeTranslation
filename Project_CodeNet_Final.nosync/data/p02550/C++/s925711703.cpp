#include<stdio.h>
#include<string.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define rep(i,N) for(long i=0;i<(long)N;i++)
static inline void PUT(char c)
{
  static char buf[1<<15],*ptr=buf;
  if(ptr==buf+strlen(buf)||c==0){fwrite(buf,1,ptr-buf,stdout),ptr=buf;}*ptr++=c;
}
static inline long IN(void)
{
  long x=0,f=0,c=getchar();while(c<48||c>57){f^=c==45,c=getchar();}
  while(c>47&&c<58){x=x*10+c-48,c=getchar();}return f?-x:x;
}
static inline void OUT(long a)
{
  if(a<0)PUT('-'),a=-a;
  int d[40],i=0;do{d[i++]=a%10;}while(a/=10);
  while(i--){PUT(d[i]+48);}PUT('\n');
}
int main()
{
  long N=IN(),calc=0;int X=IN(),MOD=IN(),vis[100001],val[100001];
  if(N<=MOD){rep(i,N){calc+=X;X=1l*X*X%MOD;}return OUT(calc),0;}
  else
  {
    rep(i,MOD+1)
    {
      val[i+1]=X;
      if(vis[X])
      {
        rep(j,vis[X]){calc+=val[j+1];}
        rep(j,i-vis[X]+1){calc+=1l*(N-2*vis[X]+i-j)/(i+1-vis[X])*val[j+vis[X]+1];}
        return OUT(calc),0;
      }
      vis[X]=i+1;X=1l*X*X%MOD;
    }	
  }
}