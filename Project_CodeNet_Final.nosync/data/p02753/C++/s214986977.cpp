#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<char> S(3);
  for(int i=0;i<3;i++){
    cin >> S.at(i);
  }
  if(S.at(0)==S.at(1)){
    if(S.at(1)==S.at(2)){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;
}
