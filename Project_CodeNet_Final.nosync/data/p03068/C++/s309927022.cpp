#include <iostream>

using namespace std;

int main(void) {
  int N, K;
  string s;
  cin >> N >> s >> K;
  for(int i = 0; i < s.size(); i++) {
    if (s[i] != s[K-1]) s[i] = '*';
  }
  cout << s << endl;
}
