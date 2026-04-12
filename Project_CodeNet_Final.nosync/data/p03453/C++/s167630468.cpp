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
#define mo 1000000007

vector<pair<int,int> > a[110000];

int d1[110000];
_int64 shortest1[110000];

int d2[110000];
_int64 shortest2[110000];

priority_queue<pair<_int64,int> > pq;
int used[110000];

int main()
{
  int i,j,k,m,n,s,t,x,y,z;
  _int64 ans,dd;
  _int64 tmp,best;
  scanf("%d%d",&n,&m);
  scanf("%d%d",&s,&t);
  s--;t--;
  for (i=0;i<n;i++)
    a[i].clear();
  for (i=0;i<m;i++)
  {
    scanf("%d%d%d",&x,&y,&z);
    x--;y--;
    a[x].push_back(make_pair(y,z));
    a[y].push_back(make_pair(x,z));
  }

  for (i=0;i<n;i++)
    shortest1[i]=(1LL<<60);
  memset(d1,0,sizeof(d1));
  d1[s]=1;
  shortest1[s]=0;
  while (!pq.empty()) pq.pop();
  pq.push(make_pair(0,s));
  memset(used,0,sizeof(used));
  while (!pq.empty())
  {
    pair<_int64,int> tmp=pq.top();
    //cout<<tmp.first<<" "<<tmp.second<<endl;
    pq.pop();
    x=tmp.second;
    dd=-tmp.first;
    if (used[x]!=0) continue;
    used[x]=1;
    for (i=0;i<a[x].size();i++)
    {
      if (dd+a[x][i].second<shortest1[a[x][i].first])
      {
        shortest1[a[x][i].first]=dd+a[x][i].second;
        d1[a[x][i].first]=d1[x];
        pq.push(make_pair(-shortest1[a[x][i].first],a[x][i].first));
      }
      else if (dd+a[x][i].second==shortest1[a[x][i].first])
      {
        d1[a[x][i].first]+=d1[x];
        if (d1[a[x][i].first]>=mo) d1[a[x][i].first]-=mo;
      }
    }
  }
  
  for (i=0;i<n;i++)
    shortest2[i]=(1LL<<60);
  memset(d2,0,sizeof(d2));
  d2[t]=1;
  shortest2[t]=0;
  while (!pq.empty()) pq.pop();
  pq.push(make_pair(0,t));
  memset(used,0,sizeof(used));
  while (!pq.empty())
  {
    pair<_int64,int> tmp=pq.top();
    pq.pop();
    x=tmp.second;
    dd=-tmp.first;
    if (used[x]!=0) continue;
    used[x]=1;
    for (i=0;i<a[x].size();i++)
    {
      if (dd+a[x][i].second<shortest2[a[x][i].first])
      {
        shortest2[a[x][i].first]=dd+a[x][i].second;
        d2[a[x][i].first]=d2[x];
        pq.push(make_pair(-shortest2[a[x][i].first],a[x][i].first));
      }
      else if (dd+a[x][i].second==shortest2[a[x][i].first])
      {
        d2[a[x][i].first]+=d2[x];
        if (d2[a[x][i].first]>=mo) d2[a[x][i].first]-=mo;
      }
    }
  }

  //cout<<shortest1[7]<<" "<<d1[7]<<endl;
  //cout<<shortest1[1]<<" "<<d1[1]<<endl;
  //cout<<shortest1[5]<<" "<<d1[5]<<endl;
  
  best=shortest1[t];
  ans=d1[t];
  ans*=d1[t];
  ans%=mo;
  //cout<<"ans:"<<ans<<endl;
  //cout<<"best:"<<best<<endl;
  for (i=0;i<n;i++)
  {
    if ((shortest1[i]==shortest2[i])&&(shortest1[i]+shortest2[i]==best))
    {
      tmp=d1[i];
      tmp*=d2[i];
      tmp%=mo;
      tmp*=d1[i];
      tmp%=mo;
      tmp*=d2[i];
      tmp%=mo;
      ans-=tmp;
      if (ans<0) ans+=mo;
    }
  }
  for (i=0;i<n;i++)
    for (j=0;j<a[i].size();j++)
    {
      x=a[i][j].first;
      if ((shortest1[i]+a[i][j].second+shortest2[x]==best)&&(shortest1[i]+shortest1[i]<best)&&(shortest2[x]+shortest2[x]<best))
      {
        tmp=d1[i];
        tmp*=d2[x];
        tmp%=mo;
        tmp*=d1[i];
        tmp%=mo;
        tmp*=d2[x];
        tmp%=mo;
        ans-=tmp;
        if (ans<0) ans+=mo;
      }
    }
  printf("%lld\n",ans);
  return 0;
}