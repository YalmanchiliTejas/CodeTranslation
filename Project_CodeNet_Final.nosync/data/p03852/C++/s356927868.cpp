#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  std::cin >> c;
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    std::cout << "vowel\n";
  } else {
    std::cout << "consonant\n";
  }
}
