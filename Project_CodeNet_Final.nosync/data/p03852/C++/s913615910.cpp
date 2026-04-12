#include <bits/stdc++.h>
using namespace std;

int main()
{
  char c;
  cin >> c;
  
  vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};

  bool is_ok = false;
  for (auto it = vowel.begin(); it != vowel.end(); it++) {
    if (c == *it) {
      is_ok = true;
      break;
    }
  }

  if (is_ok == true) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }

  return 0;
}
