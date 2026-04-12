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

struct permutation{
  vector<int> v, idx;
  ll N;
  permutation(ll n){
    v.resize(n);
    idx.resize(n);
    N = n;
    init();
  }
  void init(){
    re(i, N) v[i] = i;
  }
  bool step(){
    return next_permutation(v.begin(), v.end());
  }
  void sorted(){
    re(i, N) idx[v[i]] = i;
  }
};

int main(int argc, char const *argv[]) {
  ll x, y, n, m;std::cin >> n >> m;
  permutation p(n);
  vvl eg = vv(n, n, 0, ll);
  re(i, m){
    std::cin >> x >> y;
    eg[x-1][y-1] = eg[y-1][x-1] = 1;
  }
  ll c = 0;
  do{
    p.sorted();
    bool flag = true;
    re(i, n-1) if(eg[p.idx[i]][p.idx[i+1]]==0) flag = false;
    if(p.idx[0] == 0 && flag) c++;
  }while(p.step());
  std::cout << c << '\n';
  return 0;
}
