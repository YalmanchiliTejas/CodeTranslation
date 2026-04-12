/// Author: Wang, Yen-Jen
#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i + 1 < (int)S.size(); i++) {
    if (S[i] == 'A' && S[i + 1] == 'C') {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}
