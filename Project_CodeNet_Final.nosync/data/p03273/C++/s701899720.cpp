#include <bits/stdc++.h>
using namespace std;

int main() {
  int x , y ;
  cin >> x >> y ;

  vector<vector<char>> data(x,vector<char>(y));
  
  for(int i = 0 ; i<x ; i++){
    for(int j = 0 ; j<y; j++){
      cin >> data.at(i).at(j);
    }
  }
  
  for(int j = 0 ; j<y ; j++){
    bool tate = true ;
    for(int i = 0 ; i<x; i++){
      if(data.at(i).at(j)=='#'){
        tate = false;
        break;
      }
    }
    
    if(tate){
      for(int k = 0 ; k<x; k++){
        data.at(k).at(j)='|';
      }
    }
  }
  
  for(int i = 0 ; i<x ; i++){
    bool yoko = true ;
    for(int j = 0 ; j<y; j++){
      if(data.at(i).at(j)=='#'){
        yoko = false;
        break;
      }
    }
    
    if(yoko){
      for(int k = 0 ; k<y; k++){
        data.at(i).at(k)='-';
      }
    }
  }
  
  for(int i = 0 ; i < x ; i++){
    for(int j = 0 ; j < y ; j++){
      if(data.at(i).at(j)=='|'){
        if(j!=y-1){
          continue;
        }
        else{
          cout << endl;
          continue;
        }
      }
      if(data.at(i).at(j)=='-'){
          continue;
        
      }
      
      cout << data.at(i).at(j) ;
      if(j==y-1){
        cout << endl;
      }
    }
  }
      

}

