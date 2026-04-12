#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

  int n, k;
  string s;
  cin >> n >> s >> k;
  char a = s.at(k-1);
  
  for (int i = 0; i < n; i++) {
    if (s.at(i) != a) {
      s.at(i) = '*';
    }
  }

  cout << s << endl;
}
