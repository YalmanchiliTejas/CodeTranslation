#include <bits/stdc++.h>

using namespace std;

bool isfilled(int mas[20][20], int n)
{
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(mas[i][j] == 0) return false;
    }
  }
  return true;
}

void magic(int mas[20][20], int n, int y, int x, int m)
{
  if(isfilled(mas, n)) return;
  if(x < 0 || n <= x || y < 0 || n <= y){
    if(x < 0) x = n-1;
    if(n <= x) x = 0;
    if(y < 0) y = n-1;
    if(n <= y) y = 0;
    magic(mas, n, y, x, m);
  } else if(mas[y][x] != 0){
    magic(mas, n, y+1, x-1, m);
  } else {
    mas[y][x] = m;
    magic(mas, n, y+1, x+1, m+1);
  }
  return;
}

int main()
{
  int n;
  while(cin >> n, n){
    int mas[20][20] = {{0}};
    magic(mas, n, (n-1)/2+1, (n-1)/2, 1);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++) printf("%4d", mas[i][j]);
      puts("");
    }
  }
  
  return 0;
}