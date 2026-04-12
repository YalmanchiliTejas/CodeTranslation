#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

int main() {
  int h,w;
  cin >> h >> w;
  char maze[h][w];
  int c = 0;
  rep(i,h)rep(j,w) {
    cin >> maze[i][j];
    if (maze[i][j] == '#') {
      c++;
    }
  }

  if (h + w - 1 == c) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}
