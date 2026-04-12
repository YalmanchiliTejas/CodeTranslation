#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> path(n, vector<int>(n, 0));
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    path[a-1][b-1] = 1;
    path[b-1][a-1] = 1;
  }

  vector<int> route(n-1);
  for(int i = 0; i < n-1; i++) route[i] = i+1;

  int path_cnt = 0;
  
  do {
    bool exist = true;
    if(path[0][route[0]] == 1) {
      for(int i = 0; i < n-2; i++) {
        if(path[route[i]][route[i+1]] == 0) {
          exist = false;
          break;
        }
      }
      if(exist) path_cnt++;
    }
  } while(next_permutation(route.begin(), route.end()));

  cout << path_cnt << endl;

  return 0;
}
