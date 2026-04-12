#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int n;
  int t[15][15];

  while(cin >> n, n){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	t[i][j] = -1;
      }
    }

    int x = n / 2;
    int y = n / 2 + 1;
    int now = 2;

    t[y][x] = 1;

    while(now <= n * n){
      x = x + 1;
      y = y + 1;

      while(true){
	if(n <= x) x = 0;
	if(x < 0) x = n - 1;
	if(n <= y) y = 0;
	if(y < 0) y = n - 1;

	if(t[y][x] == -1){
	  break;
	}

	x = x - 1;
	y = y + 1;
      }

      t[y][x] = now;
      now++;
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	printf("%4d", t[i][j]);
      }
      cout << endl;
    }
  }
}