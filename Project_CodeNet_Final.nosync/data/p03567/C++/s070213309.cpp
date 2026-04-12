#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int main() {
  
  string S;
  cin >> S;

  for(int i = 0;i < S.size()-1;i++) {
    if(S.substr(i,2) == "AC") {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

}