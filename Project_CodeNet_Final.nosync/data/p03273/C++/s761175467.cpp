#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  vector<int> H_count(H), W_count(W);
  
  for(int i = 0;i < a.size(); i++){
    for(int j = 0; j < a.at(i).size();j++){
      cin >> a.at(i).at(j);
      if(a.at(i).at(j) == '.'){
        H_count.at(i)++;
        W_count.at(j)++;
      }
    }
  }
  
  for(int i = 0; i < a.size(); i++){
    if(H_count.at(i) == W) continue;
    else {
      for(int j = 0;j < a.at(i).size(); j++){
        if(W_count.at(j) == H){
          if(j % W == W -1){
            cout << endl;
          }
          continue;
        }    
        else{
          cout << a.at(i).at(j);
          if(j % W == W - 1){
            cout << endl;
          }
        }
      }  
    }
  }
  return 0;
}