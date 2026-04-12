#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  
  if (S.at(0) == S.at(1) && S.at(1) == S.at(2))
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}