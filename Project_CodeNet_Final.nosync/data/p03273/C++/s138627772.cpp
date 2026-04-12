#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  vector<vector<char>> a(N,vector<char>(M));
  vector<int> p(N),q(M);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>a.at(i).at(j);
      if(a.at(i).at(j)=='#'){
        p.at(i)++;
        q.at(j)++;
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(p.at(i) && q.at(j))cout<<a.at(i).at(j);
    }
    if(p.at(i))cout<<endl;
  }
}