#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

void bfs(vector<vector<uint64_t>>& tb, int i, int j, int h, int w) {
  queue<pair<int,int>> q;
  q.push(make_pair(i,j));
  while(!q.empty()){
    auto p=q.front();q.pop();
    int y=p.first;
    int x=p.second;
    if(tb[y][x] == 1) continue;
    uint64_t val = tb[y][x];
    tb[y][x] = 1;
    int dy[] = {1,0,-1,0};
    int dx[] = {0,1,0,-1};
    REP(k,4){
      int ny=y+dy[k];
      int nx=x+dx[k];
      if(ny<0||nx<0||ny>=h||nx>=w) continue;
      if(tb[ny][nx]==val){
        q.push(make_pair(ny,nx));
      }
    }
  }
}

int main() {
  while(1){
    int n;
    cin >> n;
    if(!n) break;
    vector<int> xa;
    vector<int> ya;
    xa.push_back(-1);
    ya.push_back(-1);
    vector<int> x1(n);
    vector<int> y1(n);
    vector<int> x2(n);
    vector<int> y2(n);
    REP(i,n){
      cin >> x1[i] >> y2[i] >> x2[i] >> y1[i];
      xa.push_back(x1[i]);
      xa.push_back(x2[i]);
      ya.push_back(y1[i]);
      ya.push_back(y2[i]);
    }
    sort(begin(xa),end(xa));
    auto xi = unique(begin(xa),end(xa));
    xa.resize(xi-begin(xa));
    sort(begin(ya),end(ya));
    auto yi = unique(begin(ya),end(ya));
    ya.resize(yi-begin(ya));
    vector<vector<uint64_t>> tb(ya.size(), vector<uint64_t>(xa.size()));
    REP(i,n){
      int bx=lower_bound(begin(xa),end(xa),x1[i]) - begin(xa);
      int ex=lower_bound(begin(xa),end(xa),x2[i]) - begin(xa);
      int by=lower_bound(begin(ya),end(ya),y1[i]) - begin(ya);
      int ey=lower_bound(begin(ya),end(ya),y2[i]) - begin(ya);
      for(int j=by;j < ey;++j){
        for(int k=bx;k < ex;++k){
          tb[j][k] += UINT64_C(1) << (i+1);
        }
      }
    }
    int cnt = 0;
    REP(i,ya.size()){
      REP(j,xa.size()){
        if(tb[i][j] != 1) {
          cnt++;
          bfs(tb,i,j,ya.size(),xa.size());
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}