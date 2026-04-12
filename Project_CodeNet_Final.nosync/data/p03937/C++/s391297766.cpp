#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0;i < N;i++)

int mx[2] = {1,0};
int my[4] = {0,1};
char mas[8][8];
bool used[8][8] = {0};
int H,W;

int dfs(int y,int x)
{
  int rec = 0;
  int ny,nx;
  if(y == H - 1 && x == W - 1){
    Rep(i,H){
      Rep(j,W){
	if(mas[i][j] == '#' && used[i][j] == false)return 0;
      }
    } 
    return 1;
  }
  Rep(i,2){
    ny = y + my[i];
    nx = x + mx[i];
    if(ny >= 0 && nx >= 0 && nx < W && ny < H && mas[ny][nx] == '#'){
      used[ny][nx] = true;
      rec += dfs(ny,nx);
      used[ny][nx] = false;
    }
  }
  return rec;
}

int main()
{

  cin >> H >> W;
  Rep(i,H){
    Rep(j,W){
      cin >> mas[i][j];
    }
  }
  used[0][0] = true;
  int sum = dfs(0,0);
  if(sum)cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}
