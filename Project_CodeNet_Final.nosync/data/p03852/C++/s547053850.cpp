#include<bits/stdc++.h>
using namespace std;
int main() {
  char vowel[] = {'a', 'i', 'u', 'e', 'o'};
  char s;
  cin >> s;
  for (int i=0; i<sizeof(vowel); i++) {
    if (s == vowel[i]) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}