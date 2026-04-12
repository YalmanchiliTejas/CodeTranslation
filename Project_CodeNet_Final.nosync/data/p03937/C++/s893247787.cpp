#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 1e9
#define LINF 1e18
#define MOD 1000000007
#define PI 3.14159265359
#define EPS 1e-10
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/**
 * Usage:
 * 
 * G[from].push_back(Edge(to, weight));
 * using Graph = vector<vector<Edge>>;
 * 
 */ 
struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

/**
 * Usage:
 * 
 * chmin(old, new);
 * chmax(old, new);
 * 
 */ 
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
void printv(vector<T>& v) {
  if (v.size() == 0) {
    cout << "\n";
    return;
  }

  Rep(i, v.size()) {
    cout << v[i] << ((i + 1 < v.size()) ? ' ' : '\n');
  }
}



int H, W;
char a[10][10];

int main () {
  cin >> H >> W;

  rep(i, H) {
    rep(j, W) {
      cin >> a[i][j];
    }
  }

  int cx = 1;
  int cy = 1;

  while (cx != W || cy != H) {
    //cout << cy << " " << cx << "\n";
    a[cy][cx] = '.';

    if (cx >= 2) {
      if (a[cy][cx-1] == '#') {
        cout << "Impossible\n";
        return 0;
      }
    }

    if (cy >= 2) {
      if (a[cy-1][cx] == '#') {
        cout << "Impossible\n";
        return 0;
      }
    }

    if (cx == W) {
      char q = a[cy+1][W];
      if (q == '.') {
        cout << "Impossible\n";
        return 0;
      } else {
        cy++;
      }
    } else if (cy == H) {
      char p = a[H][cx+1];
      if (p == '.') {
        cout << "Impossible\n";
        return 0; 
      } else {
        cx++;
      }
    } else {
      char p = a[cy][cx+1];
      char q = a[cy+1][cx];

      if (p == '.' && q == '.') {
        cout << "Impossible\n";
        return 0;
      } else if (p == '#' && q == '#') {
        cout << "Impossible\n";
        return 0;
      } else if (p == '.') {
        cy++;
      } else {
        cx++;
      }
    }

  }

  if (cx >= 2) {
    if (a[cy][cx-1] == '#') {
      cout << "Impossible\n";
      return 0;
    }
  }

  if (cy >= 2) {
    if (a[cy-1][cx] == '#') {
      cout << "Impossible\n";
      return 0;
    }
  }

  cout << "Possible\n";
}