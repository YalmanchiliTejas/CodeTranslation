#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N>>M;
  
  vector<vector<char>> vec(N, vector<char>(M));
  
  vector<bool> goodx(N, false),goody(M, false);
  
  for (int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> vec.at(i).at(j);
    }
  } 
  
  for (int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(vec.at(i).at(j) == '#'){
        goodx.at(i) = true;
        goody.at(j) = true;
      }
    }
  }  

  for (int i=0;i<N;i++){
    if (goodx.at(i)){
      for(int j=0;j<M;j++){
        if (goody.at(j)){
          cout << vec.at(i).at(j);
        }
      }
    cout << endl;
    }    
  }  
}


