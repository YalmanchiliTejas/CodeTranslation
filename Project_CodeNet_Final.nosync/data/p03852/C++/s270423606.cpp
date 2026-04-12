#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  string v = "aiueo";
  int a = 0;
  for (int i = 0; i < v.size(); i++) {
    if(c == v.at(i)) {
      a = a + 1;
    }
  }
  if (a == 1) {
    cout << "vowel" <<endl;
  } else {
    cout << "consonant" << endl;
  }
}
