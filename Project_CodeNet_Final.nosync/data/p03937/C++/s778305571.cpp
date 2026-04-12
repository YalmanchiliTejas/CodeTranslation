#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout << #x << "==" << x << endl;

const int inf = 100000000;

typedef long long ll;

#define MAX_H 8
#define MAX_W 8
int H, W;
char table[MAX_H][MAX_W];
bool checked[MAX_H][MAX_W];

void dfs(int i, int j) {

  if( i < 0 || j < 0 || H < i || W < j ) {
    return;
  }

  table[i][j] = '.';

  char down = table[i+1][j];
  char right = table[i][j+1];
  if( down == '#' &&  right != '#' ) {
    dfs(i+1, j);
  } 
  if( down != '#' &&  right == '#' ) {
    dfs(i, j+1);
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);


  cin >> H >> W;

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> table[i][j];
    }
  }

  dfs(0,0);


  bool res = true;

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(table[i][j] != '.') { res = false; }
    }
  }

  cout << (res ? "Possible" : "Impossible") << "\n";

  // for(int i = 0; i < H; i++) {
  //   for(int j = 0; j < W; j++) {
  //     cout << table[i][j];
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";


  return 0;
}
