#include <bits/stdc++.h>
using namespace std;

int main() {
  char a;
  string b="consonant";
  cin >> a;
  if (a=='a' or a=='i' or a=='u' or a=='e' or a=='o'){
    b="vowel";
  }
  cout << b << endl;
}