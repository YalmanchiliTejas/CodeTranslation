#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int ms[15][15];
int n;

void init(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == n / 2 && j == n / 2 + 1) ms[i][j] = 1;
      else ms[i][j] = -1;
    }
  }
}

pair<int, int> checkNext(pair<int, int> now){
  int nx = now.first, ny = now.second;
  if(nx < n && nx >= 0 && ny < n && ny >= 0 && ms[nx][ny] == -1) return now;
  else if(nx >= n) return checkNext(pair<int, int>(0, ny));
  else if(ny >= n) return checkNext(pair<int, int>(nx, 0));
  else if(nx < 0) return checkNext(pair<int, int>(n - 1, ny));
  else if(ny < 0) return checkNext(pair<int, int>(nx, n - 1));
  else if(ms[nx][ny] != -1) return checkNext(pair<int, int>(nx - 1, ny + 1));
}

void printMs(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%4d", ms[j][i]);
    }
    printf("\n");
  }
}

int main(void){
  while(cin >> n && n != 0){
    init();
    pair<int, int> now = pair<int, int>(n/2, n/2 + 1);
    for(int i = 2; i <= n * n; i++){
      pair<int, int> next = checkNext(pair<int, int>(now.first + 1, now.second + 1));
      ms[next.first][next.second] = i;
      now = next;
    }
    printMs();
  }
  return 0;
}