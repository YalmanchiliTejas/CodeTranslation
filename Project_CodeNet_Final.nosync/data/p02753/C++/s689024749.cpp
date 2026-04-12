#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S, answer;
  cin >> S;
  answer = "No";
  
  for(int i = 0;i < 3;i++){
    for(int j = i + 1;j < 3;j++){
      if(S.at(i) != S.at(j)){
        answer = "Yes";
      }
    }
  }
  
  
    cout << answer << endl;
}
