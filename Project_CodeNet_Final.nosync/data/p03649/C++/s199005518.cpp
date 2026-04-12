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

_int64 a[60];

int main()
{
  _int64 i,j,n,tmp,ans,b1;
  scanf("%lld",&n);
  for (i=0;i<n;i++)
    scanf("%lld",&a[i]);
  ans=0;
  b1=1;
  while (b1==1)
  {
    b1=0;
    for (i=0;i<n;i++)
      if (a[i]>=n)
      {
        b1=1;
        tmp=a[i]/n;
        a[i]%=n;
        ans+=tmp;
        for (j=0;j<n;j++)
          if (i!=j) a[j]+=tmp;
      }
  }
  printf("%lld\n",ans);
  return 0;
}