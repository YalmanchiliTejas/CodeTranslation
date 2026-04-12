#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d>>(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

typedef tuple<ll, ll, ll> tp;

int main(int argc, char const *argv[]) {
  // 不可能なものを削る
  ll a, b;std::cin >> a >> b;
  vvl d = VV(a+1, b+1, 0, ll);
  re(i, a) re(j, b) scanf("%lld", &d[i+1][j+1]);
  ll INF = 1000000000;
  vvl cost = VV(a+1, b+1, INF, ll);

  vector<tp> use;
  for(ll i=0;i<=99;i++){
    for(ll j=0;j<=99;j++){
      for(ll k=0;k<=100;k++){
        //i, j, kの時のコストが下回ったら絶対に使えない
        for(ll A=1;A<=a;A++){
          for(int B=1;B<=b;B++){
            if(i*A+j*B+k<d[A][B]) goto nxt;
          }
        }
        use.push_back(tp(i, j, k));//採用
        for(int A=1;A<=a;A++){
          for(int B=1;B<=b;B++){
            cost[A][B] = min(cost[A][B], i*A+j*B+k);
          }
        }
        break;
        nxt:;
      }
    }
  }
  for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
      if(cost[i][j]!=d[i][j]){
        std::cout << "Impossible" << '\n';
        return 0;
      }
    }
  }

  std::cout << "Possible" << '\n';
  vvl e;
  vvl ok = VV(301, 301, 0, ll);


  for(int i=1;i<100;i++){
    ok[i][i+1] = 1;
    e.push_back({i, i+1, -1});
  }
  for(int i=1;i<100;i++){
    ok[i+200][i+201] = 1;
    e.push_back({i+200, i+201, -2});
  }

  for(auto v:use){
    ll i = get<0>(v);
    ll j = get<1>(v);
    ll k = get<2>(v);
    ll x = i+1;
    ll y = 300 - j;
    if(ok[x][y]) return 1;
    ok[x][y] = 1;
    e.push_back({x, y, k});
  }

  //------output area-----
  std::cout << "300 " << e.size() << '\n';
  for(auto v:e){
    std::cout << v[0] << " " << v[1] << " ";
    if(v[2]==-1) std::cout << "X" << '\n';
    else if(v[2]==-2) std::cout << "Y" << '\n';
    else std::cout << v[2] << '\n';
  }
  std::cout << "1 300" << '\n';
  return 0;
}
