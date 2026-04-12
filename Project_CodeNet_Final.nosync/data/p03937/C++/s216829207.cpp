#include <iostream>
#include <string>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string s[9];
  for (int i=0; i<H; i++) {
    cin >> s[i];
  }

  int cnt=0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (s[i][j] == '#') cnt++;
    }
  }

  string ans = (cnt == H+W-1) ? "Possible" : "Impossible";
  cout << ans << endl;
  return 0;
}
