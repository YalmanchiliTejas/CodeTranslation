#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<unordered_map>
typedef unsigned long long ull;
typedef signed long long sll;
using namespace std;

#define INF 0x7FFFFFFFFFFFFFFF
#define BIG_PRIME 1000000007

#define DEP 19
vector<sll> data;
vector<sll> lazy;

void Add(sll l,sll r,sll a,sll k=0,sll s=0,sll t=-1)
{
  if(t<0)t=(1<<(DEP-1));
  if(t<=l||r<=s)
  {
    if(s+1<t)
    {
      lazy[2*k+1]+=lazy[k];
      lazy[2*k+2]+=lazy[k];
    }
    data[k]+=lazy[k];
    lazy[k]=0;
    return;
  }
  if(l<=s&&t<=r)
  {
    lazy[k]+=a;
    if(s+1<t)
    {
      lazy[2*k+1]+=lazy[k];
      lazy[2*k+2]+=lazy[k];
    }
    data[k]+=lazy[k];
    lazy[k]=0;
    return;
  }
  lazy[2*k+1]+=lazy[k];
  lazy[2*k+2]+=lazy[k];
  lazy[k]=0;
  Add(l,r,a,2*k+1,s,(s+t)/2);
  Add(l,r,a,2*k+2,(s+t)/2,t);
  data[k] = max(data[2*k+1],data[2*k+2]);
}

sll Max(sll l,sll r, sll k=0,sll s=0,sll t=-1)
{
  if(t<0)t=(1<<(DEP-1));
  if(t<=l||r<=s)
  {
    if(s+1<t)
    {
      lazy[2*k+1]+=lazy[k];
      lazy[2*k+2]+=lazy[k];
    }
    data[k]+=lazy[k];
    lazy[k]=0;
    return -INF;
  }
  if(l<=s&&t<=r)
  {
    if(s+1<t)
    {
      lazy[2*k+1]+=lazy[k];
      lazy[2*k+2]+=lazy[k];
    }
    data[k]+=lazy[k];
    lazy[k]=0;
    return data[k];
  }
  
  lazy[2*k+1]+=lazy[k];
  lazy[2*k+2]+=lazy[k];
  lazy[k]=0;
  sll ml,mr;
  ml=Max(l,r,2*k+1,s,(s+t)/2);
  mr=Max(l,r,2*k+2,(s+t)/2,t);
  data[k]=max(data[2*k+1],data[2*k+2]);
  return max(ml,mr);
}
sll Max(sll n)
{
  return Max(0,n+1);
}

vector<pair<sll,sll>> R[200001];

int main()
{
  data.resize(1<<DEP,0);
  lazy.resize(1<<DEP,0);
  ull i,j,N,M;
  sll l,r,a;
  cin >> N >> M;
  for(i=0;i<M;++i)
  {
    cin >> l >> r >> a;
    R[r].push_back(make_pair(l,a));
  }
  
  for(i=1;i<=N;++i)
  {
    Add(i,i+1,Max(i-1));
    for(auto itr:R[i])
    {
      Add(itr.first,i+1,itr.second);
    }
  }
  
  cout << Max(N);

  return 0;
}
