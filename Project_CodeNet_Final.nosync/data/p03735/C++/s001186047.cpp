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

int a[210000][2];
vector<int> a1,a2;
vector<int> vma,vmi;
vector<pair<int,int> > all;

int main()
{
  int i,j,k,n,ma,mai,maj,mi,mii,mij;
  _int64 ans,tmp;
  scanf("%d",&n);
  ma=0;mi=2000000000;
  vma.clear();
  vmi.clear();
  for (i=0;i<n;i++)
  {
    scanf("%d%d",&a[i][0],&a[i][1]);
    for (j=0;j<2;j++)
    {
      if (a[i][j]>ma)
      {
        ma=a[i][j];
        mai=i;maj=j;
      }
      if (a[i][j]<mi)
      {
        mi=a[i][j];
        mii=i;
        mij=j;
      }
    }
  }
  a1.clear();
  a2.clear();
  for (i=0;i<n;i++)
    if (a[i][0]>a[i][1])
    {
      a1.push_back(a[i][0]);
      a2.push_back(a[i][1]);
    }
    else
    {
      a1.push_back(a[i][1]);
      a2.push_back(a[i][0]);
    }
  sort(a1.begin(),a1.end());
  sort(a2.begin(),a2.end());
  ans=((_int64)a1[a1.size()-1]-a1[0])*((_int64)a2[a2.size()-1]-a2[0]);
  tmp=2000000000;
  all.clear();
  for (i=0;i<n;i++)
    for (j=0;j<2;j++)
    {
      all.push_back(make_pair(a[i][j],i));
    }
  sort(all.begin(),all.end());
  map<int,int> mp;
  mp.clear();
  j=0;
  for (i=0;i<all.size();i++)
  {
    while ((j<all.size())&&(mp.size()<n))
    {
      mp[all[j].second]++;
      j++;
    }
    if (mp.size()==n)
    {
      if (all[j-1].first-all[i].first<tmp) tmp=all[j-1].first-all[i].first;
    }
    mp[all[i].second]--;
    if (mp[all[i].second]==0) mp.erase(all[i].second);
  }
  tmp*=(ma-mi);
  if (tmp<ans) ans=tmp;
  printf("%lld\n",ans);
  return 0;
}