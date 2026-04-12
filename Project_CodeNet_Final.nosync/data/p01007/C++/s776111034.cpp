#include <bits/stdc++.h>

using namespace std;
int dy[] = {1,0,-1,0};
int dx[] = {0,-1,0,1};
struct A{
  int n;
  vector<vector<bool> > a;
  A(int _n){
    n = _n;
    a.resize(n);
    for(auto &e : a)e.resize(n);
  }

  void rotate(){
    int r,c,s,angle;
    cin >> r >> c >> s >> angle;
    r--;c--;
    auto temp = a;
    switch(angle){
      case 0:
      case 360:
        return;
      case 90:
        for(int i = 0 ;i < s; i++){
          for(int j = 0; j < s; j++){
            temp[i+r][j+c] = a[r+s-j-1][i+c];
          }
        }
        break;
      case 180:
        for(int i = 0 ;i < s; i++){
          for(int j = 0; j < s; j++){
            temp[i+r][j+c] = a[r+s-i-1][c+s-j-1];
          }
        }
        break;
      case 270:
        for(int i = 0 ;i < s; i++){
          for(int j = 0; j < s; j++){
            temp[i+r][j+c] = a[r+j][c+s-i-1];
          }
        }
        break;
    }
    swap(temp,a);
  }
  void invert(){
    int r,c,s; cin >> r >> c >> s;
    r--;c--;
    for(int i = r; i < r+s; i++)for(int j = c; j < c+s; j++)
      a[i][j] = !a[i][j];
  }
  void left(){
    int r; cin >> r;
    r--;
    auto temp = a;
    for(int i = 0; i < n; i++){
      temp[r][i] = a[r][(i+1)%n];
    }
    swap(temp,a);
  }
  void right(){
    int r; cin >> r;
    r--;
    auto temp = a;
    for(int i = 0; i < n; i++){
      temp[r][i] = a[r][(i+n-1)%n];
    }
    swap(temp,a);
  }
  void Irev(){
    int r,c; cin >> r >> c;
    r--;c--;
    bool t = a[r][c];
    irev(r,c,t);
  }
  void irev(int r, int c, bool t){
    for(int i = 0; i < 4; i++){
      int nr = r+dy[i], nc = c+dx[i];
      //if(nr < 0 || nr >= n || nc < 0 || nc >= n)continue;
      if(nr >= 0 && nr < n && nc >= 0 && nc < n){
        if(a[nr][nc] != t) continue; 
        a[nr][nc] = !t;
        irev(nr, nc, t);
      }
    }
  }
};




int main(){
  int n,m; cin >> n >> m;
  A a(n);
  for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
    int t;
    cin >> t;
    a.a[i][j] = (t == 1);
  }
  for(int i = 0; i < m; i++){
    int ope; cin >> ope;
    switch(ope){
      case 0:
        a.rotate();
        break;
      case 1:
        a.invert();
        break;
      case 2:
        a.left();
        break;
      case 3:
        a.right();
        break;
      case 4:
        a.Irev();
        break;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j != 0)cout << " ";
      cout << a.a[i][j];
    }
    cout << endl;
  }
  return 0;
} 
