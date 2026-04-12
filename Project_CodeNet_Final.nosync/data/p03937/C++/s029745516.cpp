#include <iostream>
#include <string>
using namespace std;
int H, W;
string s[10];
int main() {
  cin >> H >> W;
  int cnt = 0;
  for(int i = 0; i < H; ++i){
    cin >> s[i];
  }
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if(s[i][j] == '#') ++cnt;
    } 
  }
  
  cout << (cnt == H + W - 1 ? "P" : "Imp") << "ossible" << endl;
  return 0;
}
