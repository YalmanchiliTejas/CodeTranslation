#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  int res=0;
  if(a+b<2*c)
  {
    res=x*a+y*b;
  }
  else if((x<y&&b<2*c)||(x>=y&&a<2*c))
  {
    res=x*a+y*b-min(x,y)*((a+b)-2*c);
  }
  else
  {
    res=max(x,y)*2*c;
  }
  cout<<res<<endl;


  return 0;

}
