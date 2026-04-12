#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  string A;
  int c = 0;
  for(int i = 0; i < H; ++i){
    cin >> A;
    for(int j = 0; j < W; ++j){
      if(A[j] == '#') ++c;
    }
  }
  if(c == H+W-1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}
