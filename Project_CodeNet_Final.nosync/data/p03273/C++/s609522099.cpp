#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

int main(){
  int H, W;
  char a[110][110];
  bool w[110], h[110];

  cin >> H >> W;
  for(int y = 0; y < H; y++){
    for(int x = 0; x < W; x++){
      cin >> a[y][x];
    }
  }

  for(int y = 0; y < H; y++){
    bool flag = false;
    for(int x = 0; x < W; x++){
      if(a[y][x] == '#') flag = true;
    }
    h[y] = flag;
  }

  for(int x = 0; x < W; x++){
    bool flag = false;
    for(int y = 0; y < H; y++){
      if(a[y][x] == '#') flag = true;
    }
    w[x] = flag;
  }


  for(int y = 0; y < H; y++){
    if(h[y]){
      for(int x = 0; x < W; x++){
        if(h[y] && w[x]) cout << a[y][x];
      }
      cout << endl;
    }
  }

	return 0;
}
