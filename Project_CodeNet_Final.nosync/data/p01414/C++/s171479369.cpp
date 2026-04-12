#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
struct area{
  int bx, by, ex, ey;
  area(int bx, int by, int ex, int ey) :
    bx(bx), by(by), ex(ex), ey(ey) {}
  bool operator < (const area& a) const {
    if(bx != a.bx) return bx < a.bx;
    if(by != a.by) return by < a.by;
    if(ex != a.ex) return ex < a.ex;
    return ey < a.ey;
  }
  bool contain(int x, int y){
    return (bx <= x && x <= ex && by <= y && y <= ey);
  }
  void print(){
    printf("x: %d->%d y: %d->%d\n", bx, ex, by, ey);
  }
};
void print(int S){
  REP(y, 4){
    REP(x, 4) cout<<(bool)(S & (1 << (y * 4 + x)))<<" ";
    cout<<endl;
  }
}

int main(){
  int N;
  while(cin>>N){
    set<area> cand_s;
    REP(i, N){
      int w, h; cin>>h>>w;
      for(int x = -(w - 1); x < 4; x++){
        for(int y = -(h - 1); y < 4; y++){
          cand_s.insert(area(max(0, x), max(0, y), min(3, x + w - 1), min(3, y + h - 1)));
        }
      }
    }
    vector<area> cand(cand_s.begin(), cand_s.end());
    int bitmap[100][4] = {};
    char mapset[4] = "RGB";

    int grid[4][4];
    for(int y = 0; y < 4; y++){
      string s; cin>>s;
      for(int x = 0; x < 4; x++){
        for(int c = 0; c < 3; c++){
          if(s[x] == mapset[c]) grid[y][x] = c; 
        }
      }
    }
    for(int i = 0; i < cand.size(); i++){
      for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
          if(cand[i].contain(x, y)){
            bitmap[i][3] |= (1 << (4 * y + x));
            bitmap[i][grid[y][x]] |= (1 << (4 * y + x));
          }
        }
      }
    }
    int dist[1<<16];
    fill(dist, dist + (1<<16), INF);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
      int S = que.front(); que.pop();
      //printf("S:%d dist:%d\n", S, dist[S]);
      //print(S);
      //cout<<endl;
      if(S == (1<<16) - 1) break;
      for(int i = 0; i < cand.size(); i++){
        for(int c = 0; c < 3; c++){
          int nS = (S & ~bitmap[i][3]) | bitmap[i][c];
          if(dist[nS] != INF) continue;
          dist[nS] = dist[S] + 1;
          que.push(nS);
        }
      }
    }
    cout<<dist[(1<<16) - 1]<<endl;
  }
  return 0;
}