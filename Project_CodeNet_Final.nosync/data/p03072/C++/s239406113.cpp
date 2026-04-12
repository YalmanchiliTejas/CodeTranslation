#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int b = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    if (b <= h) cnt++;
    b = max(b, h);
  }
  cout << cnt << endl;
}
