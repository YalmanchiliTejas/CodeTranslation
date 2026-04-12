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
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll ans = 0, n, k;std::cin >> n >> k;
  rep(b, 1, n+1){
    if(b<=k) continue;
    if(n%b==0) ans += (n/b)*(b-k);
    else ans += (n/b)*(b-k) + max((ll)0, min(n%b, n%b - k + 1));
    //std::cout << b << " " << ans << '\n';
  }
  std::cout << ans << '\n';
  return 0;
}
