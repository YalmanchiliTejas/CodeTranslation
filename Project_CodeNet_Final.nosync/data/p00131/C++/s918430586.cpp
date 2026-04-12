#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define F first
#define S second
#define INF 1 << 30

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int a[10][10], b[10][10], res[10][10];
int dy[] = {-1,0,0,1,0}, dx[] = {0,-1,0,0,1};

int judge(int *used){
  memcpy(b, a, sizeof(a));
  memset(res, 0, sizeof(res));

  rep(i, 10){
    if(!used[i]) continue;
    res[0][i] = 1;
    rep(d, 5){
      int ny = dy[d], nx = i + dx[d];

      if(ny < 0 || nx < 0 || ny >= 10 || nx >= 10) continue;
      b[ny][nx] = !b[ny][nx];
    }
  }
  
  REP(i, 1, 10){
    rep(j, 10){
      if(!b[i-1][j]) continue;
      res[i][j] = 1;
      rep(d, 5){
	int ny = i + dy[d], nx = j + dx[d];

	if(ny < 0 || nx < 0 || ny >= 10 || nx >= 10) continue;
	b[ny][nx] = !b[ny][nx];
      }
    }
  }
 
  rep(i, 10) rep(j, 10) if(b[i][j]) return 0;

 
  return 1;
}

bool solve(int i, int *used){
  if(i == 10){
    if(judge(used)) return 1;
    return 0;
  }

  if(solve(i+1, used)) return 1;
  used[i] = 1;
  if(solve(i+1, used)) return 1;
  used[i] = 0;

  return 0;
}

int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    rep(i, 10) rep(j, 10) scanf("%d", &a[i][j]);

    int used[10];
    memset(used, 0, sizeof(used));
    solve(0, used);

    rep(i, 10){
      rep(j, 10) printf(j?" %d":"%d", res[i][j]); puts("");
    }
  }
  return 0;
}