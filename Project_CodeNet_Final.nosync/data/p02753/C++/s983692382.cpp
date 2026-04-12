#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  int na = 0;
  int nb = 0;

  for (auto c : s) {
    if (c == 'A') ++na;
    if (c == 'B') ++nb;
  }

  if (na == 2 || nb == 2) cout << "Yes" << endl;
  else cout << "No" << endl;

}