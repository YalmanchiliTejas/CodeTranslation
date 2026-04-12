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
typedef vector<pair<int,int> > vp;
int n;
int main(int argc,char const* argv[])
{
  int x;
  cin >> x;
  if(x==3 || x==5 || x==7)
    {
      cout << "YES" << endl;
    }
  else
    {
      cout << "NO" << endl;
    }
  return 0;
}
