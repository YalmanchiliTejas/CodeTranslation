#include <bits/stdc++.h>
using namespace std;

main(){
  int N,M;
  cin>>N>>M;
  int n=0;
  vector<vector<char>> data(N,vector<char>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>data.at(i).at(j);
    }
  }
  vector<int> v(N);
  vector<int> l(M);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(data.at(i).at(j)=='#'){
        n=1;
        break;  
      }
    }
    if(n==1){
      n=0;
      continue;
    }
    v.at(i)=1;
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      if(data.at(j).at(i)=='#'){
        n=1;
        break;
      }
    }
    if(n==1){
      n=0;
      continue;
    }
    l.at(i)=1;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(v.at(i)==0 && l.at(j)==0){
        cout<<data.at(i).at(j);
      }
    }
    if(v.at(i)==0){
      cout<<endl;
    }
    
  }
}