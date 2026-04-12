#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  vector<vector<char>> b(H, vector<char>(W));
    
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  b = a;
  int sum = 0;
  
  for (int i = 0; i < H; i++){
    int count = 0;
    for (int j = 0; j < W; j++){
      if (a.at(i).at(j) == '.'){
        count ++;
      }
    }
    if (count == W){
      b.erase(b.begin() + i - sum);
      sum ++;
    }
  }
  
  a = b;
  
  int sum2 = 0;
  for (int j = 0; j < W ; j++){
    int count2 = 0;
    for (int i = 0; i < H - sum; i++){
      if (a.at(i).at(j) == '.'){
        count2 ++;
      }
    }
    if (count2 == H - sum){
      for (int k = 0; k < b.size(); k++){
        b.at(k).erase(b.at(k).begin() + j - sum2);
      }
      sum2 ++;
    }
  }

  for (int i = 0; i < H - sum; i++){
    for (int j = 0; j < W - sum2; j++){
      cout << b.at(i).at(j);
      if (j == b.at(i).size() - 1){
        cout << endl;
      }
    }
  }

}