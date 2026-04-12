#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  bool ac = false;
  for(int i=0; i<s.size()-1; i++) if(s.substr(i,2)=="AC") ac = true;
  if(ac) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}