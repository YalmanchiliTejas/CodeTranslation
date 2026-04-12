#include <bits/stdc++.h>
using namespace std;

int main() {

  string S;

  cin >> S;

  bool Aflg = false;
  bool Bflg = false;

  for(int i=0; i<S.size(); i++){
    if(S.at(i) == 'A'){
      Aflg = true;
    }else{
      Bflg = true; 
    }
    if(Aflg&&Bflg){
      break;
    }
  }

  if(Aflg&&Bflg){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}
