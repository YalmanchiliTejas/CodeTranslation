#include <iostream>
#include <vector>
#include <algorithm>
int main() {
  char c;
  std::cin >> c;
  std::vector<char> v{'a', 'i', 'u', 'e', 'o'};
  std::vector<char>::iterator itr = std::find(v.begin(), v.end(), c);
  std::cout << (itr==v.end()?"consonant":"vowel");
}
            