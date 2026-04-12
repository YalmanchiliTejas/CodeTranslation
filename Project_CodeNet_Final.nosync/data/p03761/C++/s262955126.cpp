//DubiousDocument.cpp (C)
#include <iostream>
#include <string>
using namespace std;

int main(){
  int n;
  cin >> n;
  string S;
  int chk[60][30] = {0};
  for(int i = 0; i < n; i++){
    cin >> S;
    for(int j = 0; j < S.size(); j++){
      ++chk[i][S[j]-'a'];
    }
  }
  int Min = 0;
  for(int i = 0; i < 26; i++){
      for(int j = 0; j < n; j++){
        if(j == 0) Min = chk[0][i];
        else Min = min(Min,chk[j][i]);
      }
      cout << string(Min,'a'+i);
  }
  cout << endl;
  return 0;



}
