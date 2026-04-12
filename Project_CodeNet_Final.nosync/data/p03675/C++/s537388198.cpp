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

int a[210000];
int d[210000];

int main()
{
  int i,j,n,x,y,now;
  scanf("%d",&n);
  for (i=0;i<n;i++)
    scanf("%d",&a[i]);
  x=0;y=n-1;
  now=0;
  for (i=n-1;i>=0;i--)
  {
    if (now==0)
    {
      d[x]=a[i];
      x++;
    }
    else
    {
      d[y]=a[i];
      y--;
    }
    now=1-now;
  }
  for (i=0;i<n;i++)
  {
    if (i!=0) printf(" ");
    printf("%d",d[i]);
  }
  printf("\n");
  return 0;
}