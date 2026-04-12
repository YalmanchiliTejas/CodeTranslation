#include <iostream>

using namespace std;

#define REP(i, n) for(int (i) = 0; i < (n); i++)

int main() {
  const char right_hands[11] = {
    'y', 'u', 'i', 'o', 'p',
    'h', 'j', 'k', 'l',
    'n', 'm'
  };

  while (true) {
    string s;
    cin >> s;
    if (s == "#") {
      break;
    }
    int isRight = -1;
    int cnt = 0;
    REP(i, s.size()) {
      bool isR = false;
      REP(j, 11) {
        if (s[i] == right_hands[j]) {
          isR = true;
          break;
        }
      }
      
      if ((isRight == 0 && isR == true) ||
        (isRight == 1 && isR == false)) {
        cnt++;
      }
      isRight = isR;
    }
    cout << cnt << endl;
  }

  return 0;
}