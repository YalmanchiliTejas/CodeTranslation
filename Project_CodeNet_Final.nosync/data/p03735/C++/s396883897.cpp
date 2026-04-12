#include<bits/stdc++.h>
#define pi 3.1415926535897932384626
using namespace std;
      
struct P{
  int x,y,z;
  bool operator < (const P &a )const{
    //if(y!=a.y)
    return y<a.y;
  };
};

int a,b,c,d,i,k,n,m,e,dx[10]={1,0,-1,0,1,1,-1,-1},dy[10]={0,1,0,-1,1,-1,1,-1};
int o[1];
int l[1];
int j[1];

long long x,y,z,mod=1000000007;
//string r;
char r[3];

P u[200101];
priority_queue<P> q;
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

int main()
{
  scanf("%d",&a);
  int x1=mod,x2=0,y1=mod,y2=0;
  for(int t=1;t<=a;t++)
  {
    scanf("%d %d",&n,&m);
    if(n>m) swap(n,m);
    if(y2<m&&x1>n) i=1;
    else if(y2<=m||x1>=n) i=0;
    x1=min(x1,n);
    x2=max(x2,n);
    y1=min(y1,m);
    y2=max(y2,m);
    q.push({n,m});
  }
  x=(long long)(y2-y1)*(x2-x1);
  n=mod,m=0;
  k=mod;
  for(;q.size();)
  {
    m=max(m,q.top().x);
    n=min(n,q.top().x);
    q.pop();
    if(q.size()) k=min(k,max(m,q.top().y)-min(n,y1));
    else k=min(k,m-n);
  }
  printf("%lld",min(x,(long long)k*(y2-x1)));
}
//5


