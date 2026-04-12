#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool e=false;
  char prev='*';
  for(char c:s){
    if(prev=='A' && c=='C'){
      e=true;
      break;
    }
    prev=c;
  }
  if(e) cout << "Yes" << endl;
  else cout << "No" << endl;
}