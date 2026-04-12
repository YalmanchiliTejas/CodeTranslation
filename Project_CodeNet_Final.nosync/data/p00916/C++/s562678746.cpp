#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define REP2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(S) (S).begin(), (S).end()
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);

  int N;
  while (cin >> N && N){
    vector<int> L(N), T(N), R(N), B(N), X, Y;
    REP(i, N){
      cin >> L[i] >> T[i] >> R[i] >> B[i];

      for (int j = -1; j <= 1; j++){
        X.push_back(L[i] + j);
        X.push_back(R[i] + j);
        Y.push_back(T[i] + j);
        Y.push_back(B[i] + j);
      }
    }
    
    sort(ALL(X));
    X.erase(unique(ALL(X)), X.end());

    sort(ALL(Y));
    Y.erase(unique(ALL(Y)), Y.end());
    
    REP(i, N){
      L[i] = lower_bound(ALL(X), L[i]) - X.begin();
      R[i] = lower_bound(ALL(X), R[i]) - X.begin();
      
      T[i] = lower_bound(ALL(Y), T[i]) - Y.begin();
      B[i] = lower_bound(ALL(Y), B[i]) - Y.begin();
    }

    ll board[X.size()][Y.size()];
    memset(board, 0, sizeof(board));

    REP(i, N) REP2(x, L[i], R[i]) REP2(y, B[i], T[i]){
      board[x][y] |= (1LL << i);
    }

    int res = 0;
    REP(x, X.size()) REP(y, Y.size()) if (board[x][y] >= 0){
      res++;
        
      ll mask = board[x][y];
      
      typedef pair<int, int> P;

      int dx[] = {0, 1, 0, -1};
      int dy[] = {1, 0, -1, 0};
        
      queue<P> que;
      que.push(P(x, y));
        
      while (!que.empty()){
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++){
          int nx = cx + dx[i];
          int ny = cy + dy[i];
          if (nx < 0 || (int)X.size() <= nx) continue;
          if (ny < 0 || (int)Y.size() <= ny) continue;

          if (board[nx][ny] == mask){
            board[nx][ny] = -1;
            que.push(P(nx, ny));
          }
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}