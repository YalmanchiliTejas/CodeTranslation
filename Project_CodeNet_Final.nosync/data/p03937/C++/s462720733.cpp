#include <bits/stdc++.h>

#define mp       make_pair
#define mt	  make_tuple
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF=1<<29;
const double EPS=1e-9;
const ll MOD = 1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int H,W;
char board[10][10];
bool check[10][10];
int main(){
  cin >> H >> W;

  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> board[i][j];
    }
  }
  string ok = "Possible";
  string out = "Impossible";
  
  if (board[0][0] != '#' or board[H - 1][W - 1] != '#'){
    cout << out << endl;
    return 0;
  }
  int py,px;
  py = px = 0;
  while (true){
    check[py][px] = true;
    if (py == H - 1 and px == W - 1){
      break;
    }
    int ny,nx;
    
    //right
    ny = py + dy[0];
    nx = px + dx[0];
    if (ny >= 0 and ny < H and nx >= 0 and nx < W and board[ny][nx] == '#'){
      py = ny;
      px = nx;
      continue;
    }
    ny = py + dy[3];
    nx = px + dx[3];
    if (ny >= 0 and ny < H and nx >= 0 and nx < W and board[ny][nx] == '#'){
      py = ny;
      px = nx;
      continue;
    }
    cout << out << endl;
    return 0;
    //down
  }

  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (board[i][j] == '#' and !check[i][j]){
	cout << out << endl;
	return 0;
      }
    }
  }

  
  cout << ok << endl;
  
  return 0;
}
