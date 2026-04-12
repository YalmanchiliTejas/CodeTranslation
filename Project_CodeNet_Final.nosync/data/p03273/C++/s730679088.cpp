#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<char>> df(N, vector<char>(M));
  string s;
  for (int i = 0; i < N; i++){
    cin >> s;
    for (int j=0;j<M;j++){
      df.at(i).at(j) = s.at(j);
    }
  }
  //cout << df[0][0] << endl;
  int next_h, next_w;
  vector<vector<int>> memory_h(1), memory_w(1);
  vector<vector<char>> next_df(N, vector<char>(M));
  
  while (true){
    next_h = 0, next_w = 0;
    memory_h[0] = {};
    memory_w[0] = {};
    for (int i=0;i<N;i++){
      for (int j=0;j<M;j++){
        if (df.at(i).at(j) == '#'){
          memory_h[0].push_back(i);next_h++;break;
        }
      }
    }
    
    for (int j=0;j<M;j++){
      for (int i=0;i<N;i++){
        if (df.at(i).at(j) == '#'){
          memory_w[0].push_back(j);next_w++;break;
        }
      }
    }
    
    
    if (N==next_h && M==next_w){break;}

    
    for (int i=0;i<next_h;i++){
      for (int j=0;j<next_w;j++){
        next_df.at(i).at(j) = df.at(memory_h[0].at(i)).at(memory_w[0].at(j));
      }
    }

    df = next_df;
    N = next_h; M = next_w;
    
  }
  
  
  for (int i=0;i<N;i++){
    for (int j=0;j<M;j++){
      cout << df[i][j];
    }
    cout << endl;
  }
  
  
}