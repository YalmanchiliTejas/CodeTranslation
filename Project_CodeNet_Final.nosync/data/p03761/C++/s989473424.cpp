#include <bits/stdc++.h>
using namespace std;

int main(){
  
int N, kazu;
  cin >> N;
int c[26][N];
  for(int i = 0;i < 26;i++){
  for(int j = 0;j < N;j++) c[i][j] = 0;
  }
  
string s;
  
  for(int i = 0;i < N;i++){
  cin >> s;
    for(int j = 0;j < s.size();j++) c[s.at(j) - '0' - 49][i]++;    
  }
  
  for(int i = 0;i < 26;i++){
  kazu = 51;
    for(int j = 0;j < N;j++){
    kazu = min(kazu, c[i][j]);
    }
    if(kazu > 0){
      while(kazu){    
        cout << (char)(i + 'a');        
        kazu--;
    }
  }
  }

  return 0;
  
}