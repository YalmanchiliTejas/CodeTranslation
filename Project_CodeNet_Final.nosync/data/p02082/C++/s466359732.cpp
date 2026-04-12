#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll s,t;
ll p,q,m;
ll y;

int main(){
  cin>>s>>t;
  cin>>p>>q>>m;
  cin>>y;

  ll ans=y^s^t;
  cout<<ans<<endl;

  return 0;
}

