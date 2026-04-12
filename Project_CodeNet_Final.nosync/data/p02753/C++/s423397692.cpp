#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  if (S == "AAB") {
    cout << "Yes" << endl;
  }
 if (S == "ABA") {
    cout << "Yes" << endl;
  }
 else if (S == "BAA") {
    cout << "Yes" << endl;
  }
 else if (S == "ABB") {
    cout << "Yes" << endl;
  }
 else if (S == "BAB") {
    cout << "Yes" << endl;
  }
 else if (S == "BBA") {
    cout << "Yes" << endl;
  } 
 else if (S == "BBB") {
    cout << "No" << endl;
  }
  else if (S == "AAA") {
    cout << "No" << endl;
  } 

}
