#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w;
  cin>>h>>w;
  char a[h][w];
  rep(i,h) {
    rep(j,w) {
      cin>>a[i][j];
    }
  }
  int nx = 0, ny = 0;
  int dx[2] = {1,0};
  int dy[2] = {0,1};
  int dz[2] = {-1,0};
  int dw[2] = {0,-1};
  
  int nextx, nexty;
  while(true) {
    int k = 0;
    int j = 0;
    rep(i,2) {
      if(nx + dx[i]<= h-1 && ny + dy[i] <= w-1 && a[nx + dx[i]][ny + dy[i]] == '#') {
        k++;
        nextx = nx + dx[i], nexty = ny + dy[i];
      }
      if(nx + dz[i] >= 0 && ny + dw[i] >= 0 && a[nx + dz[i]][ny + dw[i]] == '#') {
        j++;
      }
    }
    // debug(k);
    // debug(nx),debug(ny);
    if(nx == h-1 && ny == w-1 && j != 2) {
      cout << "Possible" << endl;
      return 0;
    } else if(k == 0 || k == 2 || j == 2) {
      cout << "Impossible" << endl;
      return 0;
    }
    nx = nextx, ny = nexty;
  }

  return 0;
}
