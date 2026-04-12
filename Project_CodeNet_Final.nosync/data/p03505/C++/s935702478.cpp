#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
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
typedef tuple<ll,int,int> p;
typedef vector<int> vi;
set <int> st;
vector<int> videos(105);
double now=0;
queue<int> num;
ll k,a,b;
int main(int argc,char const* argv[])
{
  cin >> k >> a >> b;
  if(a<=b && a<k)
    {
      cout << -1 << endl;
      return 0;
    }
  else if(a>=k)
    {
      cout << 1 << endl;
      return 0;
    }
  else
    {
      ll ans=1;
      if((k-a)%(a-b)) ans+=2;
      ans+=(k-a)/(a-b) *2;
      cout << ans << endl;	
      return 0;
    }
}
