#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

string reversed(string s){
  string ss = s;
  reverse(ss.begin(), ss.end());
  return ss;
}

int main() {
  string s;
  cin >> s;

  if(s == "AAA" || s == "BBB") cout << "No" << endl;
  else cout << "Yes" << endl;
  
  
}

