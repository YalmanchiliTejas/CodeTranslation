#include <bits/stdc++.h>
#include <string>
using namespace std;


int main() {
  char N;
  cin >> N;
  
  string ans = "consonant";
  if (N == 'a' || N == 'i' || N == 'u' || N == 'e' || N == 'o') {
    ans = "vowel";
  }
  cout << ans << endl;
}
