#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  
  cin >> H >> W;
  
  vector<vector<char>> a(H, vector<char>(W));
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  bool loop = true;
  while(loop){
    loop = false;
    
    for(vector<vector<char>>::iterator it=a.begin(); it!=a.end(); ++it){
      bool ans = true;
      for(int j=0; j<it->size(); j++){
        if(it->at(j)=='#'){
          ans = false;
          break;
        }
      }
      
      if(ans){
        a.erase(it);
        loop = true;
        break;
      }
    }
  }
  
  loop = true;
  while(loop){
    loop = false;
    
    for(int i=0; i<a.at(0).size(); i++){
      bool ans = true;
      
      for(int j=0; j<a.size(); j++){
        if(a.at(j).at(i)=='#'){
          ans = false;
          break;
        }
      }
      
      if(ans){
        for(int j=0; j<a.size(); j++){
          a.at(j).erase(a.at(j).begin()+i);
        }
        loop = true;
        break;
      }
    }    
  }
  
  for(int i=0; i<a.size(); i++){
    for(int j=0; j<a.at(i).size(); j++){
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}
