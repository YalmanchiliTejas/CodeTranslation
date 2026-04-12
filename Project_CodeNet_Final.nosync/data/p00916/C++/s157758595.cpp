#include <bits/stdc++.h>
using namespace std;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
int main(){
  while (1){
    int n;
    cin >> n;
    if (n == 0){
      break;
    }
    vector<int> x1(n), y1(n), x2(n), y2(n);
    for (int i = 0; i < n; i++){
      cin >> x1[i] >> y2[i] >> x2[i] >> y1[i];
    }
    vector<int> xc;
    for (int i = 0; i < n; i++){
      xc.push_back(x1[i]);
      xc.push_back(x2[i]);
    }
    sort(xc.begin(), xc.end());
    xc.erase(unique(xc.begin(), xc.end()), xc.end());
    int xcnt = xc.size();
    map<int, int> mpx;
    for (int i = 0; i < xcnt; i++){
      mpx[xc[i]] = i;
    }
    for (int i = 0; i < n; i++){
      x1[i] = mpx[x1[i]];
      x2[i] = mpx[x2[i]];
    }
    vector<int> yc;
    for (int i = 0; i < n; i++){
      yc.push_back(y1[i]);
      yc.push_back(y2[i]);
    }
    sort(yc.begin(), yc.end());
    yc.erase(unique(yc.begin(), yc.end()), yc.end());
    int ycnt = yc.size();
    map<int, int> mpy;
    for (int i = 0; i < ycnt; i++){
      mpy[yc[i]] = i;
    }
    for (int i = 0; i < n; i++){
      y1[i] = mpy[y1[i]];
      y2[i] = mpy[y2[i]];
    }
    vector<vector<vector<bool>>> ok(ycnt + 1, vector<vector<bool>>(xcnt + 1, vector<bool>(4, true)));
    for (int i = 0; i < n; i++){
      for (int j = x1[i] + 1; j < x2[i] + 1; j++){
        ok[y1[i]][j][0] = false;
        ok[y2[i]][j][0] = false;
        ok[y1[i] + 1][j][2] = false;
        ok[y2[i] + 1][j][2] = false;
      }
      for (int j = y1[i] + 1; j < y2[i] + 1; j++){
        ok[j][x1[i]][1] = false;
        ok[j][x2[i]][1] = false;
        ok[j][x1[i] + 1][3] = false;
        ok[j][x2[i] + 1][3] = false;
      }
    }
    vector<vector<int>> c(ycnt + 1, vector<int>(xcnt + 1, -1));
    int ans = 0;
    for (int i = 0; i <= ycnt; i++){
      for (int j = 0; j <= xcnt; j++){
        if (c[i][j] == -1){
          c[i][j] = ans;
          queue<pair<int, int>> Q;
          Q.push(make_pair(i, j));
          while (!Q.empty()){
            int y = Q.front().first;
            int x = Q.front().second;
            Q.pop();
            for (int k = 0; k < 4; k++){
              if (ok[y][x][k]){
                int y2 = y + dy[k];
                int x2 = x + dx[k];
                if (0 <= y2 && y2 <= ycnt && 0 <= x2 && x2 <= xcnt){
                  if (c[y2][x2] == -1){
                    c[y2][x2] = ans;
                    Q.push(make_pair(y2, x2));
                  }
                }
              }
            }
          }
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}
