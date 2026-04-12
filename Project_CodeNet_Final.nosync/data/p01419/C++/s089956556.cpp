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

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
typedef pair<int, int> P;

int main(){
  int H, W, M;
  while(cin>>H>>W>>M){
    vector<string> grid(H);
    REP(i, H) cin>>grid[i];
    int c_mt[50][50];
    int c_on[50][50];
    int c_of[50][50];
    REP(y, H)REP(x, W) cin>>c_mt[y][x];
    REP(y, H)REP(x, W) cin>>c_on[y][x];
    REP(y, H)REP(x, W) cin>>c_of[y][x];
    vector<int> cx, cy;
    REP(i, M){
      int y, x; cin>>y>>x;
      cx.push_back(x); cy.push_back(y);
    }
    vector<int> time[50][50];
    time[cy[0]][cx[0]].push_back(0);
    int now = 0;
    REP(i, M - 1){
      const P null = P(-1, -1);
      P prev[50][50];
      REP(y, H)REP(x, W) prev[y][x] = null;
      queue<int> qx, qy;
      qx.push(cx[i]); qy.push(cy[i]);
      while(!qx.empty()){
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        REP(r, 4){
          int nx = x + dx[r];
          int ny = y + dy[r];
          if(valid(nx, ny, W, H) && prev[ny][nx] == null && grid[ny][nx] != '#'){
            prev[ny][nx] = P(x, y);
            qx.push(nx); qy.push(ny);
          }
        }
      }
      prev[cy[i]][cx[i]] = null;
      vector<P> path;
      P cur = P(cx[i + 1], cy[i + 1]);
      while(cur != null){
        path.push_back(cur);
        cur = prev[cur.second][cur.first];
      }
      reverse(path.begin(), path.end());
      FOR(i, 1, path.size()){
        int x = path[i].first, y = path[i].second;
        int t = now + i;
        time[y][x].push_back(t);
      }
      now += path.size() - 1;
    }
    ll ans = 0;
    REP(y, H)REP(x, W){
      if(time[y][x].empty()) continue;
      int T = time[y][x].size();
      ll dp[1010][2] = {};
      REP(i, T) dp[i][0] = dp[i][1] = (ll)1e16;
      dp[0][0] = c_on[y][x] + c_of[y][x];
      dp[0][1] = c_on[y][x];
      FOR(i, 1, T){
        int cur = min(dp[i - 1][0] + c_on[y][x], dp[i - 1][1] + (ll)c_mt[y][x] * (time[y][x][i] - time[y][x][i - 1]));
        dp[i][0] = cur + c_of[y][x];
        dp[i][1] = cur;
      }
      //printf("x = %d y = %d m = %lld\n", x, y, dp[T-1][0]);
      ans += dp[T - 1][0];
    }
    cout<<ans<<endl;
  }
  return 0;
}