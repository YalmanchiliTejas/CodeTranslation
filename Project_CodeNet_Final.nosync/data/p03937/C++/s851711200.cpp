#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  REP(i,H) cin >> A[i];

  bool flag = false;
  queue<pair<int,int>> que;
  que.push(make_pair(0, 0));
  while(!que.empty()) {
    pair<int,int> p = que.front();
    que.pop();
    
    if(p.first == H - 1 && p.second == W - 1) flag = true;
    int dx[] = {0, 1};
    int dy[] = {1, 0};
    REP(k,2) {
      int yk = p.first + dy[k];
      int xk = p.second + dx[k];
      if(xk >= W || yk >= H) continue;
      if(A[yk][xk] == '#') que.push(make_pair(yk, xk));
    }
  }

  int cnt = 0;
  REP(i,H)REP(j,W) if(A[i][j] == '#') ++cnt;
  if(cnt != H + W - 1) flag = false;

  if(flag) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}

