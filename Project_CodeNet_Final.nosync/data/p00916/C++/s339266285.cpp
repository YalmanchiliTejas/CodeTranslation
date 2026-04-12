#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 70

struct rect{
  int lowx, highx, lowy, highy;
  inline void read(){ scanf("%d%d%d%d", &lowx, &highy, &highx, &lowy); }
} rects[MAX];

int n, xs[MAX << 2], xlen, ys[MAX << 2], ylen, mark;
bool xexists[1000100], yexists[1000100];
int xidxs[1000100], yidxs[1000100];
int board[150][150];
const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline void bfs(int r, int c, int minr, int maxr, int minc, int maxc, int color){
  int ori_color = board[r][c];
  
  queue<int> rs, cs;
  board[r][c] = color;
  rs.push(r); cs.push(c);
  while(!rs.empty()){
    int fr = rs.front(); rs.pop();
    int fc = cs.front(); cs.pop();
    
    for(int i = 0; i < 4; i++){
      int nxtr = fr + dirs[i][0];
      int nxtc = fc + dirs[i][1];
      if(minr <= nxtr && nxtr < maxr && minc <= nxtc && nxtc < maxc && board[nxtr][nxtc] == ori_color){
        board[nxtr][nxtc] = color;
        rs.push(nxtr); cs.push(nxtc);
      }
    }
  }
}

inline void add(int idx){
  int minr = xidxs[rects[idx].lowx], maxr = xidxs[rects[idx].highx];
  int minc = yidxs[rects[idx].lowy], maxc = yidxs[rects[idx].highy];
  int ori_mark = mark;
  
  for(int r = minr; r < maxr; r++)
  for(int c = minc; c < maxc; c++)
    if(board[r][c] < ori_mark) bfs(r, c, minr, maxr, minc, maxc, mark++);
}

inline int cnt(){  
  int res = 0;
  
  
  for(int r = 0; r <= xlen; r++)
  for(int c = 0; c <= ylen; c++)
    if(board[r][c] != -1){ res++; bfs(r, c, 0, xlen + 1, 0, ylen + 1,-1);}
  return res;
}

int main(){
  while(scanf("%d", &n) == 1 && n){
    xlen = ylen = 0;
    mark = 1;
    memset(xexists, false, sizeof(xexists));
    memset(yexists, false, sizeof(yexists));
    memset(board, 0, sizeof(board));
    
    for(int i = 1; i <= n; i++) rects[i].read();
    for(int i = 1; i <= n; i++){
      if(!xexists[rects[i].lowx]) xs[++xlen] = rects[i].lowx, xexists[rects[i].lowx];
      if(!xexists[rects[i].highx]) xs[++xlen] = rects[i].highx, xexists[rects[i].highx];
      if(!yexists[rects[i].lowy]) ys[++ylen] = rects[i].lowy, yexists[rects[i].lowy];
      if(!yexists[rects[i].highy]) ys[++ylen] = rects[i].highy, yexists[rects[i].highy];
    }
    
    sort(xs + 1, xs + xlen + 1);
    sort(ys + 1, ys + ylen + 1);
    
    for(int i = 1; i <= xlen; i++) xidxs[xs[i]] = i;
    for(int i = 1; i <= ylen; i++) yidxs[ys[i]] = i;
    
    for(int i = 1; i <= n; i++) add(i);
    
    printf("%d\n", cnt());
  }
  return 0;
}