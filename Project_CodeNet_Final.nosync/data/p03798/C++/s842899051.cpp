#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<char> animal ={'S', 'W'};
  bool flag = false;
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      vector<char> ans(N);
      ans.at(0) = animal.at(i);
      ans.at(1) = animal.at(j);
      bool A = false;
      bool B = false;
      for(int k=2; k<N; k++){
        if((ans.at(k-1) == 'S' && S.at(k-1) == 'o') || (ans.at(k-1) == 'W' && S.at(k-1) == 'x')){
          ans.at(k) = ans.at(k-2);
        }
        else{
          if(ans.at(k-2) == 'W'){
            ans.at(k) = 'S';
          }
          else{
            ans.at(k) = 'W';
          }
        }
      }
      if((ans.at(0) == 'S' && S.at(0) == 'o') || (ans.at(0) == 'W' && S.at(0) == 'x')){
        if(ans.at(N-1) == ans.at(1)){
          A = true;
        }
      }
      else{
        if(ans.at(N-1) != ans.at(1)){
          A = true;
        }
      }
      if((ans.at(N-1) == 'S' && S.at(N-1) == 'o') || (ans.at(N-1) == 'W' && S.at(N-1) == 'x')){
        if(ans.at(N-2) == ans.at(0)){
          B = true;
        }
      }
      else{
        if(ans.at(N-2) != ans.at(0)){
          B = true;
        }
      }
      if(A && B){
        flag = true;
        for(int i=0; i<N; i++){
          cout << ans.at(i);
        }
        cout << endl;
        break;
      }
    }
    if(flag){
      break;
    }
  }
  
  if(!flag){
    cout << -1 << endl;
  }
}