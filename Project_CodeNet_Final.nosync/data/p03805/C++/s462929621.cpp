#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<pair<int,int>> edge(M);
  
  for(int i=0; i< M; i++){
    cin >> edge.at(i).first >> edge.at(i).second;
  }
  
  vector<int> node(N);
  for(int i=0; i<N; i++){
    node.at(i) = i+1; 
  }
  
  sort(node.begin(), node.end());
  
  int count = 0;
  do{
    bool complete = false;
    for(int i =0; i<N-1; i++){
      int a, b;
      bool exist = false;
      if(node.at(i) < node.at(i+1)){
        a = node.at(i);
        b = node.at(i+1);
      }else{
        a = node.at(i+1);
        b = node.at(i);
      }
      exist = false; //reset
      for(int j = 0; j < M; j++){
        if(edge.at(j).first == a && edge.at(j).second == b){
          exist = true;
        }
      }
      if(!exist) break;
      if(i == N -2) complete = true;
    }
    if(complete) count++;
  }while(next_permutation(node.begin()+1,node.end()));
  cout << count << endl;
}
