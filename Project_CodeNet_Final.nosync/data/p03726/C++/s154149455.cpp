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

vector<int> a[110000];
int used[110000];
int ch[110000];
int p[110000];

int main()
{
  int i,j,n,x,y;
  vector<int> q;
  vector<int> qq;
  scanf("%d",&n);
  if (n==1)
  {
    printf("First\n");
    return 0;
  }
  for (i=0;i<n;i++)
    a[i].clear();
  for (i=0;i+1<n;i++)
  {
    scanf("%d%d",&x,&y);
    x--;y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  memset(used,0,sizeof(used));
  memset(ch,0,sizeof(ch));
  q.clear();
  q.push_back(0);
  used[0]=1;
  p[0]=-1;
  for (i=0;i<q.size();i++)
  {
    x=q[i];
    for (j=0;j<a[x].size();j++)
    {
      if (used[a[x][j]]==0)
      {
        p[a[x][j]]=x;
        q.push_back(a[x][j]);
        used[a[x][j]]=1;
        ch[x]++;
      }
    }
  }
  memset(used,0,sizeof(used));
  qq.clear();
  for (i=0;i<n;i++)
    if (ch[i]==0) qq.push_back(i);
  for (i=0;i<qq.size();i++)
  {
    x=qq[i];
    y=p[x];
    //cout<<x<<" "<<y<<endl;
    if ((y==-1)||(used[y]==1))
    {
      printf("First\n");
      return 0;
    }
    used[x]=1;
    used[y]=1;
    if (p[y]!=-1)
    {
      ch[p[y]]--;
      if (ch[p[y]]==0)
      {
        qq.push_back(p[y]);
      }
    }
  }
  printf("Second\n");
  return 0;
}