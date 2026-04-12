#include <iostream>
using namespace std;
typedef unsigned long long u64;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  int now = 0;
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < now; ++j) {
      if (s[j] == '#') {cout << "Impossible" << endl; return 0;}
    }
    while (true) {
      if (s[now] == '.' || now == w) break;
      now++;
    }
    now--;
    for (int j = now+1; j < w; ++j) {
      if (s[j] == '#') {cout << "Impossible" << endl; return 0;}
    }
  }
  if (now != w-1) cout << "Impossible" << endl;
  else cout << "Possible" << endl;
  return 0;
}
