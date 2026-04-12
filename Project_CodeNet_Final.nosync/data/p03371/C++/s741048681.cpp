#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>

#define mod 1000000007
#define INF2 9999999999
#define INF (1<<30)
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
//#define P pair<int, int>

using namespace std;
using ll = __int64_t;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int DX[] = {1, 1, 0, -1, -1, -1, 0, 1};
int DY[] = {0, -1, -1, -1, 0, 1, 1, 1};

void solve(){
  ll a, b, c, x, y;
  ll res = 0;
  cin >> a >> b >> c >> x >> y;

  if(a+b > c*2){
    res += (c*2) * min(x, y);
    if(x != y){
      if(x > y){
        if(a > c*2){
          res += (c*2) * (x-y);
        }else{
          res += a * (x-y);
        }
      }else{
        if(b > c*2){
          res += (c*2) * (y-x);
        }else{
          res += b * (y-x);
        }
      }
    }
  }else{
    res += (a*x)+(b*y);
  }

  cout << res << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
