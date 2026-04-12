#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> vec(N,vector<char>(M));
  for (int i = 0; i < N; i++) {
    for(int j=0; j<M; j++){
      cin >> vec.at(i).at(j);
    }
  }
  
  vector<int> aisu(N);
  for(int i=0; i<N; i++){
    int a=0;
    for(int j=0; j<M;j++){
      if(vec.at(i).at(j)=='.'){
        a++;
      }
    }
    if(a==M){
      aisu.at(i)=1;
      
    }
    else
      aisu.at(i)=2;
  }
  
  for(int i=0; i<M; i++){
    int a=0;
    for(int j=0; j<N; j++){
      if(vec.at(j).at(i)=='.')
        a++;
    }
    if(a==N){
      for(int j=0; j<N; j++){
        vec.at(j).at(i)='0';
      }
    }
  }
  for(int i=0; i<N; i++){
    if(aisu.at(i)==1)
      continue;
    for(int j=0; j<M; j++){
      if(vec.at(i).at(j)!='0'){
        cout<<vec.at(i).at(j);
      }
    }
    cout<<endl;
  }

}

