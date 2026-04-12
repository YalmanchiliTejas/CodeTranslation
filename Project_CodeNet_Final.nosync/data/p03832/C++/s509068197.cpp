#include<bits/stdc++.h>
#define pi 3.1415926535897932384626
using namespace std;
      
struct P{
  int x,y;
  bool operator < (const P &a )const{
    //if(y!=a.y)
    return y<a.y;
  };
};

int a,b,c,d,i,k,n,m,e,dx[10]={1,0,-1,0,1,1,-1,-1},dy[10]={0,1,0,-1,1,-1,1,-1};
long long o[1010][1010],com[4333][4333];
long long l[4011],re[4010];
long long j[4111][4111];

long long x,y,z,mod=1000000007;
//string r;
char r[3];

P u[1];
queue<P> q;
stack<int> s;
//set<int> s;
map<int,int> p;

vector<int> v[3];


bool as(P a,P b)
{
  if(a.x!=b.x)
  return a.x<b.x;
  return a.y>b.y;
  
}

long long rr(long long x,long long y)
{
  long long p=1;
  for(;y;y/=2,x*=x,x%=mod)
  if(y%2) p*=x,p%=mod;
  return p;
}

long long g(int n,int m)
{
  if(n==m||n==0) return 1;
  if(com[n][m]>=0) return com[n][m];
  return com[n][m]=(g(n-1,m-1)+g(n,m-1))%mod;
}

long long f1(int n,int m)
{
  if(m==0) return 1;
  if(j[n][m]>0) return j[n][m];
  return j[n][m]=re[n]*f1(n,m-1)%mod;
}

long long f(int n,int m,int c)
{
  return g(n*m,c)*re[m]%mod*l[n*m]%mod*f1(n,m)%mod;
}

int main()
{
  memset(com,-1,sizeof(com));
  l[0]=re[0]=1;
  for(int t=1;t<=4000;t++)
   l[t]=l[t-1]*t%mod,re[t]=rr(l[t],mod-2);
  scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
  o[b-1][a]=1;
  for(int t=b;t<=c;t++)
  for(int w=0;w<=a;w++)
  {
    o[t][w]+=o[t-1][w];
    for(int i=d;w+i*t<=a&&i<=e;i++)
    {
      o[t][w]+=o[t-1][w+i*t]*f(t,i,w+i*t)%mod,o[t][w]%=mod;
      //printf("%d %d %d %lld\n",t,i,w+i*t,f(t,i,w+i*t));
    }
    //printf("%lld ",o[t][w]);
  }
  printf("%lld",o[c][0]);
}
//0
//15


