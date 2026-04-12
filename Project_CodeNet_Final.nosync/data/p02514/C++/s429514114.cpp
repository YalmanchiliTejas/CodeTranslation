#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int h, w;

int sx, sy;
int gx, gy;
vector<int> x[3000];
vector<int> y[3000];
int n;
int memo[100][100];
int g[100][100];

int solve(int ny, int nx){
  if(memo[ny][nx] != -1)
    return memo[ny][nx];
  
  int now = g[ny][nx];

  if(now == n) return 0;

  int ret = 1 << 30;
  int nn = x[now + 1].size();

  REP(i,nn){
    int nnx = x[now + 1][i];
    int nny = y[now + 1][i];
    if(g[nny][nnx] != now + 1){
      while(true);
    }
    ret = min(ret, abs(nx - nnx) + abs(ny - nny) + solve(nny, nnx));
  }

  return memo[ny][nx] = ret;
}

int main(){
  while(cin >> w >> h, w + h){
    n = 0;

    REP(i,3000){
      x[i] = vector<int>();
      y[i] = vector<int>();
    }

    REP(i, h){
      REP(j, w){
	string s;
	cin >> s;

	if(s != "."){
	  if(s == "S"){
	    sx = j; sy = i;
	  }else if(s == "G"){
	    gx = j; gy = i;
	  }else{
	    int num;
	    sscanf(s.c_str(), "%d", &num);
	    g[i][j] = num;
	    n = max(num, n);
	    x[num].push_back(j);
	    y[num].push_back(i);
	  }
	}
      }
    }

    x[0].push_back(sx);
    y[0].push_back(sy);
    n++;
    x[n].push_back(gx);
    y[n].push_back(gy);
    g[sy][sx] = 0;
    g[gy][gx] = n;

    memset(memo, -1, sizeof(memo));
    int ret = solve(sy, sx);

    printf("%d\n", ret);
  }
  return 0;
}