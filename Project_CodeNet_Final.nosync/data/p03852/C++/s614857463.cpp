#include <bits/stdc++.h>
using namespace std;
int main()
  {char c; cin >> c;
  string s = "aeiou";
  cout << (s.find(c) != string::npos ? "vowel" : "consonant") << endl;}