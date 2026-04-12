#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  char in;
  
  cin >> in;
  
  if (in == 'a' || in == 'e' || in == 'i' || in == 'o' || in == 'u')
      cout << "vowel" << endl;
  else 
      cout << "consonant" << endl;
}