#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;
typedef pair<int,int> P;

#define INF P(-1,-1)

class State{
public:
  P now,pre;
  State(){}
  State(P _now,P _pre){
    now = _now;
    pre = _pre;
  }
};

int h,w,n;
char t[52][52];
int c[52][52],on[52][52],off[52][52];
P jobs[1002];

bool closed[52][52];
P p[52][52][1002];
vector<int> v[52][52];

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

void bfs(int start){
  queue<State> open;
  memset(closed,0,sizeof(closed));
  open.push(State(jobs[start],INF));

  while(!open.empty()){
    State st = open.front();
    open.pop();

    if(closed[st.now.first][st.now.second]) continue;
    closed[st.now.first][st.now.second] = true;

    if(st.pre != INF){
      p[st.now.first][st.now.second][start] = st.pre;
    }

    rep(i,4){
      int nx = st.now.second + dx[i];
      int ny = st.now.first + dy[i];

      if(t[ny][nx] == '.'){
        open.push(State(P(ny,nx),st.now));
      }
    }
  }
}

void simulate1(){
  P pos = jobs[0];
  int now = 0;
  int tm = 0;

  while(1){
    v[pos.first][pos.second].push_back(tm);
    if(now == n-1) break;
    pos = p[pos.first][pos.second][now+1];
    if(pos == jobs[now+1]) now++;
    tm++;
  }
}

void simulate2(){
  int idx[52][52];
  bool light[52][52];
  memset(light,0,sizeof(light));
  memset(idx,0,sizeof(idx));

  P pos = jobs[0];
  int now = 0;
  int res = 0;

  while(1){
    if(!light[pos.first][pos.second]){
      res += on[pos.first][pos.second];
    }
    light[pos.first][pos.second] = true;

    if(now == n-1){
      res += off[pos.first][pos.second];
      light[pos.first][pos.second] = false;
      break;
    }

    if(idx[pos.first][pos.second] + 1 == v[pos.first][pos.second].size()){
      res += off[pos.first][pos.second];
      light[pos.first][pos.second] = false;
    }
    else{
      int dist =
        v[pos.first][pos.second][idx[pos.first][pos.second]+1] -
        v[pos.first][pos.second][idx[pos.first][pos.second]];
      int sw = on[pos.first][pos.second] + off[pos.first][pos.second];

      if(dist*c[pos.first][pos.second] > sw){
        light[pos.first][pos.second] = false;
        res += off[pos.first][pos.second];
      }
      else{
        res += dist * c[pos.first][pos.second];
      }
    }

    idx[pos.first][pos.second]++;
    pos = p[pos.first][pos.second][now+1];
    if(pos == jobs[now+1]) now++;
  }

  printf("%d\n",res);
}

void solve(){
  rep(i,h) rep(j,w) v[i][j].clear();
  rep(i,n){
    bfs(i);
  }

  simulate1();
  simulate2();
}

int main(){
  while(scanf("%d%d%d",&h,&w,&n) != EOF){
    rep(i,h){
      scanf("%s",t[i]);
    }

    rep(i,h) rep(j,w) scanf("%d",&c[i][j]);
    rep(i,h) rep(j,w) scanf("%d",&on[i][j]);
    rep(i,h) rep(j,w) scanf("%d",&off[i][j]);
    rep(i,n) scanf("%d%d",&jobs[i].first,&jobs[i].second);

    solve();
  }
}