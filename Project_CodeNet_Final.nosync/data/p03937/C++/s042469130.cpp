#include <bits/stdc++.h>
using namespace std;

// using ll = long long;
#define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
const int MAX = 10;



using P = pair<int, int>;
using PP = pair<P, int>;  //<<y,x>,distance>

int H,W;
bool g[MAX][MAX]; // 通れるマスならtrue
bool visited[MAX][MAX];

bool bfs(int start_y, int start_x) {
  queue<PP> q;
  PP qt = PP(P(start_y, start_x),0);
  q.push(qt);
  while(!q.empty()) {
    qt = q.front();
    int curr_x = qt.first.second;
    int curr_y = qt.first.first;
    int curr_d = qt.second;
    q.pop();
    for(int dy = 0; dy <= 1; ++dy) {
      for(int dx = 0; dx <= 1; ++dx) {
        if(!dy && !dx) continue;  // 自分の位置
        if(dy+dx == 2) continue;
        

        int next_x = curr_x + dx;
        int next_y = curr_y + dy;
        int next_d = curr_d + 1;

        // 範囲外
        if(next_x < 0 || next_x >= W) continue;
        if(next_y < 0 || next_y >= H) continue;

        // 通れないまたはすでに到達済み
        if(!g[next_y][next_x]) continue;
        if(visited[next_y][next_x]) continue;

        if(dx == 1 && curr_y+1 < H && g[curr_y+1][curr_x] && !visited[curr_y+1][curr_x]) {
          return false;
        }

        q.push(PP(P(next_y,next_x),next_d));
        visited[next_y][next_x] = true;
      }
    }
  }
  return true;
}

signed main() {
  int counter = 0;
  cin >> H >> W;
  REP(h, H) {
    REP(w, W) {
      char c;
      cin >> c;
      g[h][w] = (c == '#');
      if(g[h][w]) ++counter;
    }
  }
  bool possible = bfs(0,0);
  if(!possible) {
    cout << "Impossible" << endl;
    return 0;
  }

  int visited_counter = 1;
  REP(h, H) {
    REP(w, W) {
      if(visited[h][w]) ++visited_counter;
    }
  }
  // LOG(counter);
  // LOG(visited_counter);
  if(counter == visited_counter) {
    cout << "Possible";
  } else {
    cout << "Impossible";
  }
  cout << "\n";
  return 0;
}
/***** MAIN *****/