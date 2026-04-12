#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  char a[H][W];
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(i - 1 >= 0 && j + 1 < W){
        if(a[i][j] == '#' && a[i - 1][j + 1] == '#'){
          cout << "Impossible" << endl;
          return 0;
        }
      }
    }
  }

  cout << "Possible" << endl;
  return 0;
}
