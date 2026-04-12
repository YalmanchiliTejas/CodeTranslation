#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int max_h = 0, sum = 0;
  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    max_h = max(h, max_h);
    if (max_h == h) {
      sum++;
    }
  }
  cout << sum << endl;
  return 0;
}
