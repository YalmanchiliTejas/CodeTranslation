#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void fill(int x, int y, int c, vector<vector<int> > &map){
  map[x][y] = c;
  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx<0 || ny<0 || nx>=(int)map.size() || ny>=(int)map[0].size()) continue;
    if(map[nx][ny] == 0){
      map[nx][ny] = c;
      fill(nx, ny, c, map);
    }
  }
}

int main(){
  while(1){
    int n;
    cin >> n;
    if(n==0) break;

    vector<int> l(n),t(n),r(n),b(n);
    priority_queue<int> x, y;
    for(int i=0; i<n; i++){
      cin >> l[i] >> t[i] >> r[i] >> b[i];
      x.push(-l[i]);
      x.push(-r[i]);
      y.push(-t[i]);
      y.push(-b[i]);
    }

    int numx=1, numy=1;
    map<int, int> xtoidx, ytoidx;
    int prev=-1;
    while(!x.empty()){
      if(-x.top() != prev){
        prev = -x.top();
        xtoidx[-x.top()] = numx;
        numx += 2;
      }
      x.pop();
    }
    prev = -1;
    while(!y.empty()){
      if(-y.top() != prev){
        prev = -y.top();
        ytoidx[-y.top()] = numy;
        numy += 2;
      }
      y.pop();
    }

    vector<vector<int> > plane(numx, vector<int>(numy, 0));
    for(int i=0; i<n; i++){
      for(int j=xtoidx[l[i]]; j<=xtoidx[r[i]]; j++){
        plane[j][ytoidx[t[i]]] = plane[j][ytoidx[b[i]]] = -1;
      }
      for(int j=ytoidx[b[i]]; j<=ytoidx[t[i]]; j++){
        plane[xtoidx[l[i]]][j] = plane[xtoidx[r[i]]][j] = -1;
      }
    }

    int count = 0;
    for(int i=0; i<numx; i++){
      for(int j=0; j<numy; j++){
        if(plane[i][j]==0){
          count++;
          fill(i, j, count, plane);
        }
      }
    }
    cout << count << endl;
  }
  return 0;
}