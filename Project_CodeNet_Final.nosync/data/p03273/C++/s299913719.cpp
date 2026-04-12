#define  _USE_MATH_DEFINES

#define  rep(i, n) for(int i = 0; i < n; i++)
#define  repx(i, a, n) for(int i = a; i < n; i++)
#define  loop while(1)
#define  lli long long int
 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <utility>
#include <set>

using namespace std;
  
int main() {
  
  int h, w;
  cin >> h >> w;
  
  vector<string> grid(h, string());
  rep (i, h) cin >> grid[i];
  
  /*
  rep (i, h) {
    if (count(grid[i].cbegin(), grid[i].cend(), '#') == 0)
      grid[i].replace(grid[i].begin(), grid[i].end(), w, 'x');
  }
  */
  
  rep (i, h) {
    int cnt = 0;
    rep (j, w) if (grid[i][j] == '#') cnt += 1;
    if (cnt == 0) rep (j, w) grid[i][j] = 'x';
  } 
  
  rep (i, w) {
    int cnt = 0;
    rep (j, h) if (grid[j][i] == '#') cnt += 1;
    if (cnt == 0) rep (j, h) grid[j][i] = 'x';
  }   
  
  rep (i, h) {
    int cnt = 0;
    rep (j, w) {
      if (grid[i][j] != 'x') {
        cout << grid[i][j];
        cnt += 1;
      }
    }
    if (cnt > 0) cout << endl;
  }
  
  return 0;
}