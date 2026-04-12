 #include <bits/stdc++.h>
using namespace std;

int input(vector<vector<char>> vecX , int i){
  int sum = 0;
  for(int j = 0 ; j < vecX.at(0).size()-1 ; j++){
    if(vecX.at(i).at(j) == vecX.at(i).at(j+1)){
      sum++;
    }
  }
  return sum;
}

int main() {
  int H, W;
  cin >> H >>W;
  
  vector<vector<char>> data(H, vector<char>(W));
  
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> data.at(i).at(j);
    }
  }
  
  for(int i = 0 ; i < H ; i++){
    
    for(int j = 0 ; j < W-1 ; j++){
      
      if(data.at(i).at(j) == data.at(i).at(j+1) && data.at(i).at(j) == '.'){
        
        if(j == W-2){
          
          for(int k = 0 ; k < W ; k++){
            data.at(i).at(k) = 'a';
          }
        }else{
          continue;
        }
      }else{
        break;
      }
    }
  }

   for(int j = 0 ; j < W ; j++){
    
    for(int i = 0 ; i < H-1 ; i++){
      
      if( data.at(i).at(j) == 'a' || data.at(i).at(j) == '.' ){
        if( data.at(i+1).at(j) == 'a' || data.at(i+1).at(j) == '.' ){
          
          if(i == H-2){
          
            for(int k = 0 ; k < H ; k++){
              data.at(k).at(j) = 'a';
            }
          }else{
            continue;
          }
        }else{
          break;
        }
      }else{
        break;
      }
    }
   }
  int sum = 0;
  
    for(int i = 0 ; i < H ; i++){
    
      for(int j = 0 ; j < W ; j++){
      
        if(data.at(i).at(j) != 'a'){
        
          cout << data.at(i).at(j);
        }
        if(j == W-1 && input(data,i) != 5){
          cout << endl;
        }
      }
    }
}