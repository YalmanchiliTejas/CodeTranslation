#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<string> result(N);
  for(int i=0;i<N;i++)
    cin >> result[i];
  vector<int> save_1;
  vector<int> save_2;
  
  for (int i = 0; i < N; i++){
    int flag = 0;
    for (int j = 0; j < M; j++){
      if (result.at(i).at(j) == '#'){
        flag = 1;
        break;
      }
    }
    if (flag==0) save_1.push_back(i);
  }
  for (int i = 0; i < M; i++){
    int flag = 0;
    for (int j = 0; j < N; j++){
      if (result.at(j).at(i) == '#'){
        flag = 1;
        break;
      }
    }
    if (flag==0) save_2.push_back(i);
  }
  
  
  for (int i = 0;i < N;i++){
    int flag2 = 0;
    for (int s1 =0; s1 < save_1.size();s1++){
      if (save_1.at(s1) == i) flag2 = 1;
    }
    if (flag2 == 1) continue;
    
    for (int j =0;j < M;j++){
      int flag3 = 0;
      for (int s2 =0; s2 < save_2.size();s2++){
        if (save_2.at(s2) == j) flag3 = 1;
      }
      if (flag3 == 1) continue;
      cout << result.at(i).at(j);
    }
  cout << endl;
  }
}