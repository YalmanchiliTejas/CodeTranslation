#include <iostream>
#include <string>

using namespace std;

bool whitch(char c) {
  if (c == 'y' || c == 'u' || c == 'i' ||
      c == 'o' || c == 'p' || c == 'h' ||
      c == 'j' || c == 'k' || c == 'l' ||
      c == 'n' || c == 'm')
    return true;
  else
    return false;
}

int main(int argc, char *argv[]) {
  string s;
  while (true) {
    cin >> s;
    if (s == "#")
      break;

    int count = 0;
    bool hand = whitch(s[0]);

    for (int i = 1; i < s.size(); i++) {
      if (hand != whitch(s[i])) {
        count++;
        hand = !hand;
      }
    }

    cout << count << endl;
  }
  return 0;
}