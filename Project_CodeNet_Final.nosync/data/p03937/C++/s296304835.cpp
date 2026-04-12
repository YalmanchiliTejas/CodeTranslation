#include <iostream>
using namespace std;

int H = 0, W = 0;

bool check(int nx, int ny, char *A) {
  if ((nx>=W) || (ny>=H)) {
    return false;
  } else if (A[nx+ny*W]=='#') {
    return true;
  } else {
    return false;
  }
}

int main() {
  cin >> H >> W;
  char A[W*H];
  char buf;
  int sh = 0;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> buf;
      A[j+i*W] = buf;
      if (buf == '#') {
        sh++;
      }
    }
  }
  

  int cnt = 1;
    for (int x = 0, y = 0; x < W && y < H;){
      if (check(x+1,y,A)) {
        x++;
        cnt++;
      } else if (check(x,y+1,A)) {
        y++;
        cnt++;
      } else {
        if (x == W-1 && y == H-1 && cnt == sh) {
          cout << "Possible" << endl;
          return 0;
        } else {
          cout << "Impossible" << endl;
          return 0;
        }
      }
  }
}
