#include <iostream>
#include <string>
using namespace std;

char f(char sw1, char sw2, char tf) {
  if ((sw2 == 'S' && tf == 'o') || (sw2 == 'W' && tf == 'x'))
    return sw1;
  return sw1 == 'S' ? 'W' : 'S';
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  string t[4] = {"SS", "SW", "WS", "WW"};
  for (int i = 0; i < 4; i++) {
    string ans = t[i];
    for (int j = 0; j < n-2; j++) {
      ans += f(ans[j], ans[j+1], s[j+1]);
    }
    if (f(ans[n-2], ans[n-1], s[n-1]) != ans[0]) continue;
    if (f(ans[n-1], ans[0], s[0]) != ans[1]) continue;
    cout << ans << endl;
    return 0;
  }
  cout << -1 << endl;
}