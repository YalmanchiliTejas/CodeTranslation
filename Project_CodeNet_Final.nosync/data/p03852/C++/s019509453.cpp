#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  for (auto a : {'a', 'i', 'u', 'e', 'o'}) {
    if (c == a) return cout << "vowel" << "\n", 0;
  }
  cout << "consonant" << "\n";
}