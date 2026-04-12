#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vl vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll N, ans = 1000000000000000000, ma = 0, mi = 1000000000000000000;
  std::cin >> N;
  vvl ab = vv(N, 2, 0, ll);

  for(int i=0;i<N;i++){
    std::cin >> ab[i][0] >> ab[i][1];
    if(ab[i][0]<ab[i][1]) swap(ab[i][0], ab[i][1]);
    mi = min(mi, ab[i][1]);
    ma = max(ma, ab[i][0]);
  }
  ll bmin = 0, mmax = 1000000000000000000;
  for(int j=0;j<N;j++){
    bmin = max(bmin, ab[j][1]);
    mmax = min(mmax, ab[j][0]);
  }
  ans = (bmin - mi) * (ma - mmax);
  for(int i=0;i<N;i++){
    if(ab[i][0]==ma&&ab[i][1]==mi){
      std::cout << ans << '\n';
      return 0;
    }
  }
  multimap<ll, ll> num;
  for(int i=0;i<N;i++) {
    if(ab[i][0]==ma) swap(ab[i][0], ab[i][1]);
    else if(ab[i][1]!=mi) swap(ab[i][0], ab[i][1]);
    num.emplace(ab[i][0], ab[i][1]);
  }
  while(true){
    auto itr = num.begin();
    auto it = --num.end();
    ll x =(*it).first, y = (*itr).first, z = (*itr).second;
    ans = min(ans, (ma-mi)*(x - y));
    if(z!=mi&&z!=ma&&y<z) num.erase(itr),num.emplace(z, y);
    else break;
  }
  std::cout << ans << '\n';
  return 0;
}
