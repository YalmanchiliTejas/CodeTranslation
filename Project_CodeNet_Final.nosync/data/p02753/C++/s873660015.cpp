#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ans = true;
  if (s.at(0)=='A' && s.at(1) =='A'&& s.at(2)=='A'){
    ans = false;
  }
  if (s.at(0)=='B' && s.at(1) =='B' && s.at(2)=='B'){
    ans = false;
  }
  cout <<(ans ? "Yes":"No")<<endl;
  return 0;
  
  
}