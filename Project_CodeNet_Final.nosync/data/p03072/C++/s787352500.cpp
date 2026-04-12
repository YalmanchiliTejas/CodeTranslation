#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;

  int a = 0;
  int t = 0;

  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    if (h >= t) {
      a++;
      t = h;
    }
  }

  cout << a << endl;
}