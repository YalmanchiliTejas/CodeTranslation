#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  string a = "consonant";
  cin >> c;
  if (c=='a'||c=='i'||c=='u'||c=='e'||c=='o') a = "vowel";
  cout << a << endl;
}
