#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

int main(int argc, char* argv[]) {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  /* */
  char c;
  cin >> c;
  switch (c) {
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      cout << "vowel" << endl;
      break;
    default:
      cout << "consonant" << endl;
  }
  /* */

  return EXIT_SUCCESS;
}
