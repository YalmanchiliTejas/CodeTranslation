#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int h, w;
vector<string> mat;
bool ans = false;

void dfs(int x, int y){
  if(x == w-1 && y == h-1){
    bool isok = true;
    rep(i, h){
      rep(j, w){
        if(mat[i][j] == '#') isok = false;
      }
    }
    if(isok) ans = true;
  }
  if(x+1 < w && mat[y][x+1] == '#'){
    mat[y][x+1] = '.';
    dfs(x+1, y);
    mat[y][x+1] = '#';
  }
  if(y+1 < h && mat[y+1][x] == '#'){
    mat[y+1][x] = '.';
    dfs(x, y+1);
    mat[y+1][x] = '#';
  }
}
    
    
  

int main(){
  cin >> h >> w;
  vector<string> origin(h);
  rep(i, h) cin >> origin[i];
  mat = origin;
  mat[0][0] = '.';
  dfs(0, 0);
  if(ans) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}