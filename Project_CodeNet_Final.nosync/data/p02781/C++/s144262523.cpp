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

ll n, k;
string s;
vvv dp = vvvl(105, 200, 2, -1);

ll calc(ll t, ll K, ll f){
  if(t==-1) return (K==k?1:0);
  if(dp[t][K][f]!=-1) return dp[t][K][f];

  ll ret = 0;
  ll to = s[104 - t] - '0';
  if(f==1){
    for(int i=0;i<=9;i++){
      ret += calc(t-1, (i==0?K:K+1), f);
    }
  }else{
    for(int i=0;i<to;i++) ret += calc(t-1, (i==0?K:K+1), 1);
    ret += calc(t-1, (to==0?K:K+1), 0);
  }
  return dp[t][K][f] = ret;
}

int main(int argc, char const *argv[]) {
  std::cin >> s;
  std::cin >> k;
  while(s.size()!=105) s = '0' + s;
  std::cout << calc(104, 0, 0) << '\n';
  return 0;
}
