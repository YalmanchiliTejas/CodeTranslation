#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool b = 0;
  for(int i = 1; i < s.size(); i++){
    if(s.at(i-1) == 'A' && s.at(i) == 'C'){
      b = 1;
      break;
    }
  }
  if(b)
    cout << "Yes"  << endl;
  else
    cout << "No" << endl;
      
}
