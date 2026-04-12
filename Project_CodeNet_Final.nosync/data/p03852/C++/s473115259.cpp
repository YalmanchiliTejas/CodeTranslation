#include<bits/stdc++.h>
using namespace std;

int main(void) {
  char c;
  vector<char> v{'a', 'e', 'i', 'o', 'u'};
  cin >> c;
  if (count(v.begin(), v.end(), c)) cout << "vowel";
  else cout << "consonant";
}