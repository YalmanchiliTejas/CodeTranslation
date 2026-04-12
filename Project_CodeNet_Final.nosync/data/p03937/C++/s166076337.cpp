#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  char grid[h+1][w+1];

  int cnt = 0;
  for(int y=1; y<=h; y++){
    for(int x=1; x<=w; x++) {
      cin >> grid[y][x];
      if(grid[y][x] == '#') cnt++;
    }
  }

  if(cnt == h+w-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;

  return 0;
}
