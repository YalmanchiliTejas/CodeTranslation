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
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
typedef __int128_t lll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll a, b, c, x, y;std::cin >> a >> b >> c >> x >> y;
  ll ans = 1000000000000;
  for(int i=0;i<=200000;i+=2){
    ll tmp = i*c;
    ll A = max((ll)0, x - i/2);
    ll B= max((ll)0, y - i/2);
    ans = min(ans, tmp+A*a+B*b);
  }
  std::cout << ans << '\n';
  return 0;
}
