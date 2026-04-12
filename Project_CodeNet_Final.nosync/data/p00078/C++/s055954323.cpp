#include <iostream>
using namespace std;
int field[15][15] = {};
int x,y,n;


int main() {
  while(cin >> n,n) {
    int field[15][15] = {};
    x = (n-1)/2;
    y = (n-1)/2 + 1;
    field[y][x] = 1;
    x++;
    y++;

    for(int i=1;i<n * n;i++) {
    onemore:
      if(y<n && x<n) {
      }
      else if(x == n && y == n) {
        x = 0;
        y = 0;
      }
      else if(x == n) { //migi
        x = 0;
      }
      else if(y == n) {
        y = 0;
      }

      if(field[y][x] != 0) {
        x -= 1;
        y += 1;
        if(x == -1) x = n-1;
        goto onemore;
      }
      else {
        field[y][x] = i+1;
        x++;
        y++;
      }
    }

    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        printf("%4d",field[i][j]);
      }
      cout << endl;
    }
  }
}