#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  int cnt = 0;
  vector<vector<bool> > a(h+1, vector<bool>(w+1, false));
  char c;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> c;
      if(c == '#'){
        a[i][j] = true;
        cnt++;
      }
    }
  }

  int start[2] = {0, 0};
  int right[2] = {0, 1};
  int down[2] = {1, 0};
  int step = 1;
  while(true){
    if(start[0] == h-1 && start[1] == w-1){
      break;
    }
    if(a[right[0]][right[1]] == a[down[0]][down[1]]){
      cout << "Impossible" << endl;
      return 0;
    }
    if(a[right[0]][right[1]]){
      start[1] = right[1];
    }else if (a[down[0]][down[1]]){
      start[0] = down[0];
    }

    right[0] = start[0] ; right[1] = start[1] + 1;
    down[0] = start[0] + 1; down[1] = start[1];
    step++;
  }

  if(step == cnt){
    cout << "Possible" << endl;
  }else{
    cout << "Impossible" << endl;
  }
  return 0;
}
