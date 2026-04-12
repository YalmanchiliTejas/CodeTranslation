#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

int h[16],w[16];
int dist[1<<16];
char ba[4][4];
int ok[1<<16];

int main() {
  int n;
  cin >> n;
  REP(i,n) cin >> h[i] >> w[i];
  REP(i,4) REP(j,4) cin >> ba[i][j];
  int num = 0;
  set<int> masks;
  REP(i,n) {
    for (int y1=-h[i]+1; y1<4; ++y1) {
      for (int x1=-w[i]+1; x1<4; ++x1) {
        int mask = 0;
        for (int y=y1; y<y1+h[i]; ++y) {
          for (int x=x1; x<x1+w[i]; ++x) {
            if (y>=0&&y<4&&x>=0&&x<4) mask |= 1<<(y*4+x);
          }
        }
        masks.insert(mask);
      }
    }
  }

  // FOR(it, masks) {
  //   int S = *it;
  //   REP(y,4) {
  //     REP(x,4)
  //       cout << (S>>(y*4+x)&1);
  //     cout << endl;
  //   }
  //   cout << endl;
  // }
  REP(S,1<<16) {
    set<char> st;
    REP(y,4) {
      REP(x,4) {
        if (S>>(y*4+x)&1) {
          st.insert(ba[y][x]);
        }
      }
    }
    ok[S] = (st.size() <= 1);
    // if (ok[S]) {
    //   REP(y,4) {
    //     REP(x,4)
    //       cout << (S>>(y*4+x)&1);
    //     cout << endl;
    //   }
    //   cout << endl;
    // }
  }
  queue<int> Q;
  Q.push((1<<16)-1);
  memset(dist,-1,sizeof(dist));
  dist[(1<<16)-1] = 0;
  while(!Q.empty()) {
    int S = Q.front(); Q.pop();
    if (S == 0) break;
    FOR(it, masks) {
      int t[3]={};
      if (ok[*it & S]) {
        int T = S & ~*it;
        if (dist[T] == -1) {
          dist[T] = dist[S] + 1;
          Q.push(T);
        }
      }
    }
  }
  cout << dist[0] << endl;
}