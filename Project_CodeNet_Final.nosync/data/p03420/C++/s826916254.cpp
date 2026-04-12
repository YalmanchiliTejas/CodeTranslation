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

int main()
{
  _int64 ans,tmp;
  int a,b,n,k;
  scanf("%d%d",&n,&k);
  ans=0;
  for (b=k+1;b<=n;b++)
  {
    ans+=(n/b)*(b-k);
    tmp=n%b;
    if (tmp>=k) ans+=tmp-k+1;
    if (k==0) ans--;
  }
  printf("%lld\n",ans);
  return 0;
}