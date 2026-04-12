#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool k=true;
  for(int i=0;i<3;i++) {
    if(s.at(i)=='A') {
      continue;
    }
    else if(s.at(1)=='B') {
      break;
    }
    else if(s.at(i)=='B') {
      k=false;
      break;
    }
    else{
    }
  }
  for(int i=0;i<3;i++) {
    if(s.at(i)=='B') {
      continue;
    }
    else if(s.at(1)=='A') {
      break;
    }
    else if(s.at(i)=='A') {
      k=false;
      break;
    }
    else{
    }
  }
  if(k==true) {
    cout << "No" <<endl;
  }
  else {
    cout << "Yes" <<endl;
  }
  
}
