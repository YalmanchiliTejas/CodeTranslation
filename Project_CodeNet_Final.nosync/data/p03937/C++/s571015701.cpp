#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) REP(i,0,n)
#define REP(i,a,n) for(int i = a ; i < (int)n ; i++)

int H, W;
string field[10];
int dx[] = {1, 0};
int dy[] = {0, 1};
int cnt;

void dump(){
  rep(i,H){
    rep(j, W){
      cout << field[i][j];
    }
    puts("");
  }
  puts("");
}

void check(){
  rep(i,H){
    rep(j, W){
      if(field[i][j]=='#'){
	cout << "Impossible" << endl;
	exit(0);
      }
    }
  }
  cout << "Possible" << endl;    
  exit(0);
}
void solve(int x, int y){

  field[y][x] = '.';
  

  if(x == W-1 && y == H-1){
    check();
  }

  if(field[y+1][x]=='#' && field[y][x+1]=='#') return;

  rep(i, 2){
    int nx = x + dx[i]; int ny = y + dy[i];
    if(0 <= nx && nx < W && 0 <= ny && ny < H && field[ny][nx]=='#'){
      solve(nx, ny);
    }
  }
}


int main(){
  cin >> H >> W;
  
  rep(i, H) cin >> field[i];
  
  solve(0,0);
  
  check();
}
