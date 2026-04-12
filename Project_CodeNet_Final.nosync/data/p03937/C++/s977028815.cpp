#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << H << " "; debug_out(T...); }
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int h,w;
  cin >> h >> w;
  vector<string> A(h);
  rep(i,h) cin >> A[i];
  queue<P> que;
  que.push(P(0,0));
  vector<vector<bool> > visited(h,vector<bool>(w,false));
  visited[0][0] = true;
  bool ok = true;
  while(!que.empty()) {
    P p = que.front(); que.pop();
    rep(i,2) {
      int nx = p.second + dx[i];
      int ny = p.first + dy[i];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
      if (visited[ny][nx] || A[ny][nx] == '.') continue;
      visited[ny][nx] = true;
      que.push(P(ny,nx));
      break; //ここまできたら抜ける
    }
  }
  rep(y,h) rep(x,w) {
    if (!visited[y][x] && A[y][x] == '#') {
      ok = false; break;
    }
  }
  if (ok) cout << "Possible\n";
  else cout << "Impossible\n";
  return 0;
}