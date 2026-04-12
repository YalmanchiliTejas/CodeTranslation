#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string condition = "";
  cin >> condition;
  
  int a_cont = 0, b_cont = 0;
  for (char c : condition) {
    if (c == 'A') a_cont++;
    if (c == 'B') b_cont++;
  }
  
  if (a_cont == 0 || b_cont == 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
  
}