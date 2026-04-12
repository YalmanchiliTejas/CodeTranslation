#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  string S;  
  cin >> S;
  
  string result = "Yes";
  
  if (S.at(0) == S.at(1) && S.at(1) == S.at(2)) {
    result = "No"; 
  }
  
  cout << result << endl;

}