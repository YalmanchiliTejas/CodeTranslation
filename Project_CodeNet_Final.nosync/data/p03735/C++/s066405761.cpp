#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<queue>
#define LL long long
#define nw ans=min(ans,(LL)(R1-R2)*(B1-B2))
using namespace std;
inline int read( )
{
  int sum=0;char c=getchar( );bool f=0;
  while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0'&&c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
  return sum;
}
const int N=200005;
int n,suf[N];
struct ex{int x,y;}d[N];
inline bool operator < (const ex &a,const ex &b) {return a.x<b.x;}
int main( )
{
  int i,x,y,R1,R2,B1,B2,pre;LL ans=1e18;
  n=read( );R1=0;R2=1e9;
  for(i=1;i<=n;i++)
    {
      x=read( );y=read( );
      if(x>y) d[i].x=y,d[i].y=x;
      else d[i].x=x,d[i].y=y;
      R1=max(R1,d[i].y);
      R2=min(R2,d[i].y);
    }
  sort(d+1,d+n+1);
  B1=d[n].x;B2=d[1].x;nw;
  R2=d[1].x;B1=max(B1,d[1].y);pre=d[1].y;
  for(i=2;i<n;i++) 
    {
      if((B2=d[i].x)>pre) break;
      nw;B1=max(B1,d[i].y);pre=min(pre,d[i].y);
    }
  B2=pre;nw;
  printf("%lld",ans);
  return 0;
}