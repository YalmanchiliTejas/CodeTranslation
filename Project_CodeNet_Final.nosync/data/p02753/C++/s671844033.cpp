#include <bits/stdc++.h>
using namespace std;

int main() {
 string S;
 cin >> S;
  if(S.at(0) != S.at(1)||S.at(1) != S.at(2)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}