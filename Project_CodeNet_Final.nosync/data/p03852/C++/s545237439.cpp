#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  cin >> c;
  char a = 'a', e = 'e', i = 'i', o = 'o', u = 'u';
  if (c == a || c == e || c == i || c == o || c == u) {
    cout << "vowel" << endl;
  }
  else { cout << "consonant" << endl;}
}