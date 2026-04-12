#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int count;
   for (int i = 0; i < 3; i++) {
    if (S.at(i) == 'A') {
      count++;
    }
  }
  if (count == 0 || count == 3 ) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}