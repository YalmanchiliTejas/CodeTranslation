#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

#define _int64 long long

int d[20][20];
int dd[20][20][2];
int used[110][110];
int adder[20][20];

int main()
{
  int i,j,a,b,k,l,ss,tt,n,st1,st2,b1,b2,o,p,prev;
  vector<pair<pair<int,int>,int> > ans;
  scanf("%d%d",&a,&b);
  for (i=1;i<=a;i++)
    for (j=1;j<=b;j++)
    {
      scanf("%d",&d[i][j]);
    }
  memset(dd,-1,sizeof(dd));
  
  for (i=1;i<=a;i++)
    for (j=1;j<=b;j++)
    {
      b1=0;
      for (k=0;k<110;k++)
      {
        for (l=0;l<110;l++)
        {
          if (k*i+l*j>d[i][j]) continue;
          b2=1;
          adder[i][j]=d[i][j]-k*i-l*j;
          for (o=1;o<=a;o++)
            for (p=1;p<=b;p++)
              if (adder[i][j]+o*k+p*l<d[o][p]) b2=0;
          if (b2==0) continue;
          b1=1;
          dd[i][j][0]=k;
          dd[i][j][1]=l;
          break;
        }
        if (b1==1) break;
      }
      if (b1==0)
      {
        printf("Impossible\n");
        return 0;
      }
    }
  printf("Possible\n");
  ans.clear();
  ss=0;
  st1=0;
  n=1;
  prev=0;
  for (i=0;i<110;i++)
  {
    ans.push_back(make_pair(make_pair(prev,n),-1));
    prev=n;
    n++;
  }
  tt=n;
  st2=n;
  prev=n;
  n++;
  for (j=0;j<110;j++)
  {
    ans.push_back(make_pair(make_pair(n,prev),-2));
    prev=n;
    n++;
  }
  memset(used,0,sizeof(used));
  //cout<<dd[1][1][0]<<" "<<dd[1][1][1]<<" "<<adder[1][1]<<endl;
  for (i=1;i<=a;i++)
    for (j=1;j<=b;j++)
    {
      if (used[dd[i][j][0]][dd[i][j][1]]==0)
      {
        used[dd[i][j][0]][dd[i][j][1]]=1;
        ans.push_back(make_pair(make_pair(st1+dd[i][j][0],st2+dd[i][j][1]),adder[i][j]));
      }
    }
  printf("%d %d\n",n,(int)ans.size());
  for (i=0;i<ans.size();i++)
  {
    printf("%d %d ",ans[i].first.first+1,ans[i].first.second+1);
    if (ans[i].second==-1) printf("X\n");
    else if (ans[i].second==-2) printf("Y\n");
    else printf("%d\n",ans[i].second);
  }
  printf("%d %d\n",ss+1,tt+1);
  return 0;
}