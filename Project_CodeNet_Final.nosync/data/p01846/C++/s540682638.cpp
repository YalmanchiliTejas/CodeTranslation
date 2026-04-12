#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

vector<vector<char>> toGrid(string s) {
  vector<vector<char>> grid;
  s = s + '/';
  int n = s.size();
  vector<char> add;
  for (int i = 0; i < n; i++) {
    if (s[i] == '/') {
      grid.push_back(add);
      add.resize(0);
    } else {
      if (s[i] == 'b') {
        add.push_back('b');
      } else {
        int cnt = s[i] - '0';
        while (cnt--) 
          add.push_back('.');
      }
    }
  }

  return grid;
}

string toJfan(vector<vector<char>> grid) {
  int h = grid.size();
  int w = grid[0].size();
  string ret = "";
  for (int i = 0; i < h; i++) {
    int cnt = 0;
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == 'b') {
        if (cnt > 0) {
          ret += (char)(cnt + '0');
        }
        ret += 'b';
        cnt = 0;
      } else cnt++;
    }
    if (cnt > 0) {
      ret += (char)(cnt + '0');
    }

    if (i != h - 1) {
      ret += '/';
    }
  }

  return ret;
}

bool solve() {
  string s; cin >> s;
  if (s == "#") return false;
  
  // jfan -> grid
  auto grid = toGrid(s);
  
  /*
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  */

  int i, j, ii, jj;
  cin >> i >> j >> ii >> jj;
  i--;
  j--;
  ii--;
  jj--;

  grid[i][j] = '.';
  grid[ii][jj] = 'b';

  string jfan = toJfan(grid);
  cout << jfan << endl;
  return true;
}

int main() {
  
  while (solve()) {
  }
  return 0;
}

