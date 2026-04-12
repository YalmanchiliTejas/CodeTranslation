#include <cstdio>
#include <string>

using namespace std;

const string right_hand = "yuiop hjkl nm";

int main() {
  bool last_right = false, not_first = false;
  int cnt = 0, c;
  while ((c=getchar()) != '#') {
    if (c == '\n') {
      printf("%d\n", cnt);
      last_right = false;
      not_first = false;
      cnt = 0;
    } else {
      bool right = (right_hand.find((char)c) != string::npos);
      if (right != last_right && not_first) cnt++;
      last_right = right;
      not_first = true;
    }
  }
  return 0;
}