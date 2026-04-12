#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
  int n;
  int t[20][20];

  while(cin >> n, n){
    int x = n / 2, y = n / 2 + 1;
    int cnt = 0;

    memset(t, -1, sizeof(t));

    while(cnt < n * n){
      if(n <= x)      x = 0;
      else if(x < 0)  x = n - 1;
      else if(n <= y) y = 0;
      else if(y < 0)  y = n - 1;
      else if(t[y][x] != -1){
        x--;
        y++;
      }
      else{
        t[y][x] = cnt + 1;
        x++;
        y++;
        cnt++;
      }
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        printf("%4d", t[i][j]);
      }
      cout << endl;
    }
  }
}