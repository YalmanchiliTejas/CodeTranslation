#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  int H, W;

  cin >> H >> W;

  char mat[102][102];

  REP(i, H){
    REP(j, W){
      cin >> mat[i][j];
    }
  }

  vector<int> ig_x, ig_y;
  bool isB = true;
  REP(i, H){
    REP(j, W){
      if (mat[i][j] != '.') {
        isB = false;
        break;
      }
    }
    if (isB) ig_x.push_back(i);
    isB = true;
  }

  REP(j, W){
    REP(i, H){
      if (mat[i][j] != '.') {
        isB = false;
        break;
      }
    }
    if (isB) ig_y.push_back(j);
    isB = true;
  }

  // for (auto iter = ig_x.begin(); iter != ig_x.end(); iter++){
  //   cout << *iter;
  // }

  if (ig_x.size() == 0) ig_x.push_back(1000);
  if (ig_y.size() == 0) ig_y.push_back(1000);

  int k = 0;
  int l = 0;
  REP(i, H){
    if (ig_x[k] == i){
      k++;
    } else {
      REP(j, W){
        if (ig_y[l] == j){
          l++;
        }else {
          cout << mat[i][j];
        }
      }
      l = 0;
      cout << endl;
    }
  }
  return 0;
}
