#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<queue>
#define LL long long
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
int n,cnt;
struct ex{int num,next;}map[N*2];
int head[N],d[N],len;bool del[N];
inline void link(int x,int y)
{
  len++;map[len].num=y;map[len].next=head[x];head[x]=len;d[x]++;
  len++;map[len].num=x;map[len].next=head[y];head[y]=len;d[y]++;
}
queue<int>q;
int main( )
{
  int i,x,y,k;
  n=read( );
  if(n&1) {puts("First");return 0;}
  for(i=1;i<n;i++) x=read( ),y=read( ),link(x,y);
  for(i=1;i<=n;i++) if(d[i]==1) q.push(i);
  while(!q.empty( ))
    {
      x=q.front( );q.pop( );y=0;
      if(del[x]) continue;
      for(i=head[x];i;i=map[i].next)
	if(!del[k=map[i].num]) {y=k;break;}
      if(!y) {puts("First");return 0;}
      del[x]=1;del[y]=1;
      for(i=head[y];i;i=map[i].next)
	if((--d[k=map[i].num])==1) q.push(k);
    }
  puts("Second");
  return 0;
}