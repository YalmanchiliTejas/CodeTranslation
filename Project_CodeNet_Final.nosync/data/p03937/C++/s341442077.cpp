#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>>grid;

int h, w;

bool find(int x, int y, int c){
  if(grid[x][y]=='.' || c<0)return false;
  if(c==0 && x==h && y==w)return true;
  return (find(x+1, y, c-1) || find(x, y+1, c-1));
}

int main(){
  cin >> h >> w;
  int c=0;
  grid.resize(h+2, vector<char>(w+2, '.'));
  for(int i=1; i<=h; i++){
    for(int j=1; j<=w; j++){
      cin >> grid[i][j];
      if(grid[i][j]=='#')c++;
    }
  }
  if(find(1, 1, c-1))cout << "Possible";
  else cout << "Impossible";
  return 0;
}
  