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

int used[10];
int a[10][10];
int ans,n;

void search(int x)
{
  int i,b1;
  b1=0;
  for (i=0;i<n;i++)
    if (used[i]==0) b1=1;
  if (b1==0)
  {
    ans++;
    return;
  }
  for (i=0;i<n;i++)
    if ((used[i]==0)&&(a[x][i]==1))
    {
      used[i]=1;
      search(i);
      used[i]=0;
    }
}

int main()
{
  int i,m,x,y;
  scanf("%d%d",&n,&m);
  memset(a,0,sizeof(a));
  for (i=0;i<m;i++)
  {
    scanf("%d%d",&x,&y);
    x--;y--;
    a[x][y]=1;
    a[y][x]=1;
  }
  memset(used,0,sizeof(used));
  used[0]=1;
  ans=0;
  search(0);
  printf("%d\n",ans);
  return 0;
}