#include <bits/stdc++.h>
using namespace std;

int main() {long H; long W; cin >> H >> W;

char str[H][W];
for(int i = 0; i < H; i++){
  for(int j = 0; j < W; j++){
    cin >> str[i][j];
  }
}
vector<int> s(H); vector<int> t(W);
for(int i = 0; i < H; i++){
  for(int j = 0; j < W; j++){
    if(str[i][j] == '#'){
      s.at(i) = 1;
      break;
    }
  }
}
  for(int j = 0; j < W; j++){
    for(int i = 0; i < H; i++){
    if(str[i][j] == '#'){
      t.at(j) = 1;
      break;
    }
  }
}

for(int i = 0; i < H; i++){
  if(s.at(i) == 1){
  for(int j = 0; j < W; j++){
    if(t.at(j) == 1){
      cout << str[i][j];
    }
  }
  cout << endl;
  }
}




// char ans = str[1][1];
//  cout << ans << endl;
 return 0;
 }