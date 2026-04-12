#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  const string v = "aiueo";
  cout << (v.find(c) != string::npos ? "vowel" : "consonant") << endl;
}