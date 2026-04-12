#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  getline(cin, S);
  bool ans = false;
  for(int i = 0; i < S.size() - 1; i++){
  	if(S.at(i) != S.at(i + 1)){
      ans = true;
      break;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}