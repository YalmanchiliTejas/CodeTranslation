#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  string s1 = "AAA";
  string s2 = "BBB";
  if (s1<S && S<s2) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}