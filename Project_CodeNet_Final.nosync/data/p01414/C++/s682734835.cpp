#include <set>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define f first
#define s second
#define mp make_pair


using namespace std;

int h[20];
int w[20];
int n;
char dist[10][10];

int memo[1<<16];
const int bad = 1000000;

int mask[16][8][8];
int smemo[16][8][8][3];

const char *color = "RGB";

int depth = 0;
int ans   = bad;

void genmemo(){
  REP(k,n){
    int hh = h[k];
    int ww = w[k];
    REP(cc, 3){
      char col = color[cc];
      for(int y = -hh + 1; y < 4; y++){
	for(int x = -ww + 1; x < 4; x++){
	  int next = 0;
	  int msk  = 0;
	  REP(i,hh) REP(j,ww){
	    int yy = i + y;
	    int xx = j + x;

	    if(yy < 0) continue;
	    if(xx < 0) continue;
	    if(yy > 3) continue;
	    if(xx > 3) continue;

	    if(dist[yy][xx] == col){
	      next |= (1 << (yy * 4 + xx));
	    }
	    msk |= (1 << (yy * 4 + xx));
	  }

	  mask[k][y+4][x+4] = msk;
	  smemo[k][y+4][x+4][cc] = next;
	}
      }
    }
  }

}

int solve(int now){
  if(now == (1 << 16) - 1)
    return 0;
  if(memo[now]) return memo[now];
  memo[now] = bad;

  int ret = bad;
  // int cnt = __builtin_popcount(now);

  REP(k,n){
    int hh = h[k];
    int ww = w[k];
    REP(cc, 3){
      for(int y = -hh + 1; y < 4; y++){
	for(int x = -ww + 1; x < 4; x++){
	  int next = (now & (~mask[k][y+4][x+4])) | smemo[k][y+4][x+4][cc];
	  if(now != next && smemo[k][y+4][x+4][cc])
	    ret = min(ret, 1 + solve(next));
	}
      }
    }
  }

  return memo[now] = ret;
}

int main(){
  scanf("%d", &n);
  REP(i,n) scanf("%d%d", h+i, w+i);
  REP(i,4) scanf("%s", dist[i]);
  genmemo();

  typedef pair<int,int> data;
  queue<int> q;
  memset(memo, -1, sizeof(memo));

  memo[0] = 0;
  q.push(0);

  while(q.size()){
    int now = q.front();
    int kai = memo[now];
    q.pop();


    if(now == (1 << 16) - 1){
      printf("%d\n", kai);
      break;
    }

    REP(k,n){
      int hh = h[k];
      int ww = w[k];
      REP(cc, 3){
	for(int y = -hh + 1; y < 4; y++){
	  for(int x = -ww + 1; x < 4; x++){
	    int next = (now & (~mask[k][y+4][x+4])) | smemo[k][y+4][x+4][cc];
	    if(now != next && smemo[k][y+4][x+4][cc] && memo[next] == -1){
	      memo[next] = kai + 1;
	      q.push(next);
	    }
	  }
	}
      }
    }
  }

  return 0;
}