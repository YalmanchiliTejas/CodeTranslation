#include <iostream>
#include <string>

using namespace std;

char migi[11] = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm'};

bool ismigi(char c) {
  for (int j=0; j<11; j++) {
    if (migi[j] == c) {
      return true;
    }
  }
  return false;
}

int main() {
  string s;
  while( cin >> s && s != "#" ) {
    int ans = 0;
    bool right = ismigi(s[0]);
    for (unsigned int i=0; i<s.size(); i++) {
      if (ismigi(s[i]) != right) {
	ans++;
	right = !right;
      }
    }
    printf("%d\n", ans);
  }
}