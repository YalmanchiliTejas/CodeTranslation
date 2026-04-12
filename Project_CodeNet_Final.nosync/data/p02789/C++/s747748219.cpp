#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream> 
#include <cmath>
#include <map>
#include <queue>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const ll MOD=ll(1e9+7);
 
//repetition
#define REP(i,n)  for(ll i=0;i<n;i++)
 
ll P_POW(ll i, ll n) {
  if(n==0) return 1;
 
  n--;
  ll rep = i;
 
  while(n) {
    rep = rep * i;
    n--;
  }
  return rep;
} 
 
unsigned GetDigit(unsigned num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}
 
unsigned binarySearch(ll target, ll max, ll min) {
  while((max - min) > 1) {
      if((max + min)/2 > target) {
        max = (max + min)/2;
        min = min;
      } else {
        max = max;
        min = (max + min)/2;
      }
    }
}
 
ll solve(ll n) {
    if (n % 2 == 1) return 0;
 
    ll res = 0;
    n /= 2;
    int c = 1;
 
    while ((ll) n/((ll)pow(5,c))) {
      res += n/P_POW(5,c);
      c++;
    }
    return res;
}
 
void f(int rest, string s) {
  char abc[] = "abc";
  if(rest == 0) {
    cout << s << endl;
  } else {
    for(int i=0; i < 3; i++) {
      f(rest - 1, s+abc[i]);
    }
  }
} 


ll h, w;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// origin (ox, oy) destination (dx, dy)
ll dfs(ll ox, ll oy, vector<vector<char>> v, vector<vector<int>> dist) {

  int m = 0;
  for (int i = 0; i < 4; i++) {
    int nx = ox+dx[i], ny = oy + dy[i];
    if(nx < 0 || nx >= w || ny < 0 || nx >= h) continue;
    if(v[nx][ny] != '.') continue;

    if(dist[nx][ny] == -1) {
      dist[nx][ny] = dist[ox][oy] + 1;

      dist[nx][ny] = min(dist[ox][oy], dist[nx][ny]);

      cout << "v[nx][ny]: " << dist[nx][ny] << endl;
      /*
      cout << "dx: " << dx << endl;
      cout << "dy: " << dy << endl;
      cout << "v[ox][oy]: " << v[ox][oy] << endl;
      cout << "(nx, ny)" << "("<< nx << "," << ny << ")"<< endl;
      */
      dfs(nx, ny, v, dist);
    }
    m = max(m, dist[nx][ny]);
  }
  return m;
}

int bfs2(const vector<string> &v, int x, int y) {
    int H = v.size(), W = v[0].size();
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int,int>> que;

    int res = 0;
    que.push({x, y});
    dist[x][y] = 0;
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        res = max(res, dist[x][y]);
        que.pop();
        cout << "-------" << endl;
        //cout << "(nx, ny)" << "("<< nx << "," << ny << ")"<< endl;
        cout << "(x, y)" << "("<< x << "," << y << ")"<< endl;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x+ dx[dir], ny = y + dy[dir];
            //cout << "v[nx][ny]: " << v[nx][ny] << endl;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (v[nx][ny] == '#') continue;
            if (dist[nx][ny] == -1) {
                cout << "(nx, ny)" << "("<< nx << "," << ny << ")"<< endl;
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
    return res;
}
 
int main() {
  ll n, m;
  cin >> n >> m;
  if(n == m) cout << "Yes";
  else cout << "No";
}

