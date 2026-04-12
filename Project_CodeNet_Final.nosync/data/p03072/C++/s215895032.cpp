#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int h, best = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> h;
    if (best <= h) {
      best = h;
      ans++;
    }
  }
  cout << ans << endl;
}
