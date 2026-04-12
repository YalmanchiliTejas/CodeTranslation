#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  cin >> c;
  string hantei = "consonant";
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    hantei = "vowel";
  }
  
  cout << hantei << endl;
}