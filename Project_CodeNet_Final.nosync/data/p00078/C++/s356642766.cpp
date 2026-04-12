#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  int n;
  int field[15][15];

  while(cin >> n, n){
    memset(field, 0, sizeof(field));

    int x = n / 2;
    int y = n / 2 + 1;

    field[y][x] = 1;

    x++, y++;
    int cnt = 2;
    
    while(cnt != n*n+1){
      if(field[y][x] > 0 && 0 <= x && x < n && 0 <= y && y < n){
	x--, y++;
	continue;
      }
      else if(x >= n){
	x = 0;
	continue;
      }
      else if(x < 0){
	x = n-1;
	continue;
      }
      else if(y >= n){
	y = 0;
	continue;
      }
      field[y][x] = cnt;
      cnt++, x++, y++;
    }
  
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
	printf("%4d", field[i][j]);
      }
      cout << endl;
    }
  }
  return 0;
}


  