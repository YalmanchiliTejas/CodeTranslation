#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <tuple>
#include <queue>
#include <set>
#include <math.h>
#include <array>
#include <list>
#include <set>
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<ll,int,int> tup;
typedef vector<int> vi;
typedef vector<pii> vpii;
int n;
ll ans1=0;
ll ans2=0;
ll a[100005];
int x[100005];
int x2[100005];
int main(int argc,char const* argv[])
{
  cin >> n;
  memset(a,0,sizeof(a));
  memset(x,0,sizeof(x));
  memset(x2,0,sizeof(x2));
  for(int i=0;i<n;i++)
    {
      cin >> a[i];
    }
  sort(a,a+n,greater<int>());
  for(int i=0;i<n;i++)
    {
      if(i==0) x[i]=-1;
      else if(i%2!=0 && i!=n-1)
	{
	  x[i]=2;
	}
      else if(i%2!=0 && i==n-1)
	{
	  x[i]=1;
	}
      else if(i%2==0 && i!=n-1)
	{
	  x[i]=-2;
	}
      else if(i%2==0 && i==n-1)
	{
	  x[i]=-1;
	}
    }
  for(int i=0;i<n;i++)
    {
      if(i==0) x2[i]=1;
      else if(i%2!=0 && i!=n-1)
	{
	  x2[i]=-2;
	}
      else if(i%2!=0 && i==n-1)
	{
	  x2[i]=-1;
	}
      else if(i%2==0 && i!=n-1)
	{
	  x2[i]=2;
	}
      else if(i%2==0 && i==n-1)
	{
	  x2[i]=1;
	}
    }
  sort(x,x+n,greater<int>());
  sort(x2,x2+n,greater<int>());
  for(int i=0;i<n;i++)
    {
      ans1+=x[i]*a[i];
    }
  for(int i=0;i<n;i++)
    {
      ans2+=x2[i]*a[i];
    }
  cout << max(ans1,ans2) << endl;
  return 0;
}
