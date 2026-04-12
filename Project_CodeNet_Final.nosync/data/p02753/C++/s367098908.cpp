#include <bits/stdc++.h>

using namespace std;

int main(){
  bool b = true;
  string input;
  set<char> s;
  getline(cin, input);
  
  for (int i =0; i < input.size(); i++){
    s.insert(input[i]);
  }
  
  s.size() == 1 ? cout<<"No" : cout<<"Yes" ;

  return 0;
}
