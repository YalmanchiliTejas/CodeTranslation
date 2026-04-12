#include <iostream>
#include <cstdio>

using namespace std;
string str;

char leftKey[] = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b'};

bool inLeft(char c) {
  for (int i = 0; i < sizeof(leftKey); i++) {
    if (c == leftKey[i]) {
      return true;
    }
  }
  return false;
}

void solve() {
  int isLeft = inLeft(str[0]);
  int cnt = 0;
  
  for (int i = 1; i < str.size(); i++) {
    if (isLeft != inLeft(str[i])) {
      isLeft = inLeft(str[i]);
      cnt++;
    }
  }
  printf("%d\n", cnt);
}

int main() {
  while (true) {
    getline(cin, str);
    if (str == "#") {
      return 0;
    }
    solve();
  }
}