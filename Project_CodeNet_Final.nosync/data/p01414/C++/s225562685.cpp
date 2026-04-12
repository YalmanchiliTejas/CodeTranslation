#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
const int MAXN = 16;
const int H = 4;
const int W = 4;
const char C[3] = {'R','G','B'};
const int INF = 1<<28;
 
int n;
char goal[H][W];
int h[MAXN], w[MAXN];
bool vis[1<<(W*H)];
 
inline int getId(const int &x, const int &y) {
  return x + y * W;
}
 
int stamp(int state, int x, int y, int w, int h, char c) {
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < w; ++j) {
      int nx = x + j;
      int ny = y + i;
      if(nx < 0 || nx >= W) continue;
      if(ny < 0 || ny >= H) continue;
      int id = getId(nx,ny);
      state = (state & ~(1<<id));
      if(goal[ny][nx] == c) state |= (1<<id);
    }
  }
  return state;
}
 
int bfs() {
  queue<int> que;
  int vis[1<<(W*H)];
  que.push(0);
  fill(vis,vis+(1<<(W*H)), INF);
  vis[0] = 0;
  while(!que.empty()) {
    int s = que.front();
    que.pop();
    for(int k = 0; k < n; ++k) {
      for(int m = 0; m < 3; ++m) {
    for(int x = 1-w[k]; x < W; ++x) {
      for(int y = 1-h[k]; y < H; ++y) {
        int ns = stamp(s,x,y,w[k],h[k],C[m]);
        if(vis[ns] != INF) continue;
        vis[ns] = vis[s] + 1;
        que.push(ns);
        if(ns == (1<<(W*H))-1) return vis[ns];
      }
    }
      }
    }
  }
  return INF;
}
 
int main() {
  while(cin >> n) {
    for(int i = 0; i < n; ++i) {
      cin >> h[i] >> w[i];
    }
    for(int i = 0; i < H; ++i) {
      for(int j = 0; j < W; ++j) {
    cin >> goal[i][j];
      }
    }
    cout << bfs() << endl;
  }
  return 0;
}