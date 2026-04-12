#include <bits/stdc++.h>
using namespace std;

int main() 
{
  char c;
  cin >> c;
  string S = "aiueo";
  bool b = false;
  
  for (int i=0;i<S.size();i++){
    if (c==S.at(i)) b=true;
  }
  
  if (b) cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}

