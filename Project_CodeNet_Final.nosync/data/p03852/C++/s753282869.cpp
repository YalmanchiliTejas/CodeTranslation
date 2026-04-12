#include <bits/stdc++.h>
using namespace std;

int main() {
  char s;
  cin >> s;
  bool b = s=='a' || s=='i' || s=='u' || s=='e' || s=='o';
  if (b) cout << "vowel" << endl;
  else cout << "consonant" << endl;
}