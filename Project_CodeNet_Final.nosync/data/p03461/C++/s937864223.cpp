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
int o[191][111];
int l[110][199];
int j[111];

long long x,y,z,mod=1000000007;
//string r,r1;
char r[1];

P u[10];
queue<P> q;
//stack<int> s;
map<int,int> p;
vector<int> v;

bool as(P a,P b)
{
  return a.x>b.x;
}

int main()
{
  scanf("%d %d",&a,&b);
  for(int t=1;t<=a;t++)
    for(int w=1;w<=b;w++)
    {
      scanf("%d",&l[t][w]);
      for(int i=0;i*t<=l[t][w];i++)
      for(int j=0;i*t+j*w<=l[t][w];j++)
      o[i][j]=max(o[i][j],l[t][w]-i*t-j*w);
    }
  for(int t=1;t<=a;t++)
  for(int w=1;w<=b;w++)
  {
    int p=mod;
    for(int i=0;i*t<=l[t][w];i++)
    for(int j=0;i*t+j*w<=l[t][w];j++)
    p=min(p,i*t+j*w+o[i][j]);
    if(p!=l[t][w])
    {
      puts("Impossible");
      return 0;
    }
  }
  puts("Possible");
  printf("%d %d\n",100+100+2,100+100+(100+1)*(100+1));
  for(int t=1;t<=100;t++)
    printf("%d %d X\n",t,t+1);
  for(int t=100+2;t<200+2;t++)
    printf("%d %d Y\n",t,t+1);
  for(int i=1,t=0;i<=100+1;t++,i++)
  for(int j=200+2,w=0;j>=100+2;j--,w++)
    printf("%d %d %d\n",i,j,o[t][w]);
  printf("1 %d",200+2);
}
