#include <iostream>
#include <algorithm>

using namespace std;

int h[21];

int main(void) {
  int N; cin >> N;
  for (int i = 0; i < N; i++)
    cin >> h[i];

  int c = 0;
  for (int i = 0; i < N; i++) {
    bool flag = true;
    for (int j = 0; j < i; j++) {
      if (h[j] > h[i]) {
        flag = false;
        break;
      }
    }
    c += flag ? 1: 0;
  }

  cout << c << endl;

  return 0;
}