#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  char aiueo[] = {'a', 'i', 'u', 'e', 'o'};
  bool flag = false;

  cin >> c;

  for (int i = 0; i < 5 ; i++) {
    if (aiueo[i] == c) {
      flag = true;
    }
  }

  if (flag) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
}
