#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> vec(M,vector<int>(2));
  for(int i=0; i<M; i++){
    for(int j=0; j<2; j++){
      cin >> vec.at(i).at(j);
    }
  }
  vector<int> perx(N-1);
  for(int i=0; i<N-1; i++){
    perx.at(i) = i+2;
  }
  
  int cnt = 0;
  
  do{
    int exist = 0;
    vector<int> per(N);
    per.at(0) = 1;
    for(int i=0; i<N-1; i++){
      per.at(i+1) = perx.at(i);
    }
    for(int i=0; i<N-1; i++){
      int x = per.at(i);
      int y = per.at(i+1);
      for(int j=0; j<M; j++){
        if(vec.at(j).at(0) == x && vec.at(j).at(1) == y){
          exist++;
          break;
        }
        if(vec.at(j).at(0) == y && vec.at(j).at(1) == x){
          exist++;
          break;
        }
      }
    }
    if(exist == N-1){
      cnt++;
    }
    
  }
  while(next_permutation(perx.begin(),perx.end()));
  
  cout << cnt << endl;
}