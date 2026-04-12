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

vector<pair<int,int> > a;
int ans[220000];

int main()
{
  int i,j,n,x;
  scanf("%d",&n);
  for (i=0;i<n;i++)
  {
    scanf("%d",&x);
    a.push_back(make_pair(x,i));
  }
  sort(a.begin(),a.end());
  for (i=0;i<n;i++)
  {
    if (i<n/2)
    {
      ans[a[i].second]=a[n/2].first;
    }
    else
    {
      ans[a[i].second]=a[n/2-1].first;
    }
  }
  for (i=0;i<n;i++)
    printf("%d\n",ans[i]);
  return 0;
}