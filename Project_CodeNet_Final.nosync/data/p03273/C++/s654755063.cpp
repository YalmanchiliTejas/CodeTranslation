#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  set<int> br, bc;
  vector<vector<char>> A(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> A.at(i).at(j);
      if(A.at(i).at(j) == '#'){
        br.insert(i);
        bc.insert(j);
      }
    }
  }
  
  int cnt =0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(br.count(i) == 1  && bc.count(j) == 1 ){
        cout << A.at(i).at(j);
        cnt++;
        if(cnt == bc.size()){
          cout << endl;
          cnt = 0;
        }
      }
    }
  }  
}
