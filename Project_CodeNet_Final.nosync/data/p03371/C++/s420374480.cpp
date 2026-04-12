#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <math.h>
#include <array>
#include <list>
#include <set>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> tup;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> p;
typedef vector<p> vp;

int a,b,c,x,y,half;
ll ans=0;
int main(int argc,char const* argv[])
{
  cin >> a >> b >> c >> x >> y;
  half=min(x,y);
  if(2*c<a+b)
    {
      x-=half;
      y-=half;
      ans+=2*half*c;   
      if(x!=0)
	{
	  if(a*x>2*x*c)
	    {
	      ans+=2*x*c;
	    }
	  else
	    {
	      ans+=a*x;
	    }
	}
      else if(y!=0)
	{
	  if(b*y>2*y*c)
	    {
	      ans+=2*y*c;
	    }
	  else
	    {
	      ans+=b*y;
	    }
	}
    }
  else
    {
      ans+=a*x;
      ans+=b*y;
    }
  cout << ans << endl;
  return 0;
}
