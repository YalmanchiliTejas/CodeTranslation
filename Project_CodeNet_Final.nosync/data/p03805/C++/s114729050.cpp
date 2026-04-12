#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){

  int N, M; cin >> N >> M;

  bool graph[N][N];
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      graph[i][j] = false;
    }
  }

  for (int i = 0; i < M; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    graph[a][b] = true;
    graph[b][a] = true;
  }
  
  int array[N - 1];
  for (int i = 0; i < N - 1; i++){
    array[i] = i + 1;
  }

  int ans = 0;
  do{
    bool all_visit = true;

    for (int i = 0; i < N - 1; i++){
      if (i == 0){
        if (graph[0][array[i]] == false){
          all_visit = false;
          break;
        }
      }else{
        if (graph[array[i - 1]][array[i]] == false){
          all_visit = false;
          break;
        }
      }
    }
    if (all_visit == true){
      ans++;
    }
  }while(next_permutation(array, array + N - 1));

  cout << ans << endl;

  return 0;
}
