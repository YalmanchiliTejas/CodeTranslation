#include<bits/stdc++.h>
using namespace std ;

int main(){
  int H , W ; 
  cin >> H >> W ; 
  vector<vector<char>> a(H , vector<char>(W));
  vector<int> T(H) ,Y(W)  ; 
  
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> a.at(i).at(j) ; 
      if(a.at(i).at(j) == '#'){
        T.at(i)++ ;
        Y.at(j)++ ; 
      }
    }
  }
  
  for(int i = 0 ; i < H ; i++){
    int cnt = 0 ; 
    
    for(int j = 0 ; j < W ; j++){
      if(T.at(i) != 0 && Y.at(j)!=0){
        cout << a.at(i).at(j) ;
        cnt++ ; 
      }
      
    }
          if(cnt > 0 )cout << endl ; 

  }
  
}