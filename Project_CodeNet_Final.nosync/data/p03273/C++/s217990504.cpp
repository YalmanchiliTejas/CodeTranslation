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
#define MAX 100
#define MOD 1000000007
#define pb push_back

/* add vars here */

int h,w;
char a[101][101];

/* add your algorithm here */

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> wa;
  vector<int> ha;


  rep(i,h) {
    char s = a[i][0];
    if (s == '#') continue;
    for (int j = 1; j < w; ++j) {
      if (s != a[i][j]) break;
      if (j == w-1) {
        wa.pb(i);
      }
    }
  }


  rep(i,w) {
    char s = a[0][i];
    if (s == '#') continue;
    for (int j = 1; j < h; ++j) {
      if (s != a[j][i]) break;
      if (j == h-1) {
        ha.pb(i);
      }
    }
  }



  for (int i = 0; i < h; ++i) {
    bool flag = true;
    for (auto itr = wa.begin(); itr != wa.end(); ++itr) {
      if (*itr == i) {
        flag = false;
        break;
      }
    }
    if (!flag) continue;
    for (int j = 0; j < w; ++j) {
      bool flag2 = true;
      for (auto itr = ha.begin(); itr != ha.end(); ++itr) {
        if (*itr == j) {
          flag2 = false;
          break;
        }
      }
      if (!flag2) continue;
      cout << a[i][j];
    }
    cout << endl;
  }

}
