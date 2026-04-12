#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> data(H,vector<char>(W));
  vector<vector<int>> ref(H,vector<int>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> data.at(i).at(j);
    }
  }
  
  for(int i=0; i<H; i++){
    
    bool ans = false;
    
    for(int j=0; j<W; j++){
      if(data.at(i).at(j) == '#'){
        ans = true;
        break;
      }
    }
    if(ans == false){
      for(int j=0; j<W; j++){
        ref.at(i).at(j) = 1;
      }
    }
  }
  
  for(int i=0; i<W; i++){
    
    bool ans = false;
    
    for(int j=0; j<H; j++){
      if(data.at(j).at(i) == '#'){
        ans = true;
        break;
      }
    }
    if(ans == false){
      for(int j=0; j<H; j++){
        ref.at(j).at(i) = 1;
      }
    }
  }
  
  for(int i=0; i<H; i++){
    
    bool check = false;
    for(int j=0; j<W; j++){
      if(ref.at(i).at(j) != 1){
        cout << data.at(i).at(j);
      }
      if(ref.at(i).at(j) == 0){
        check = true;
      }
    }
    if(check == true){
      cout << endl;
    }
  }
}