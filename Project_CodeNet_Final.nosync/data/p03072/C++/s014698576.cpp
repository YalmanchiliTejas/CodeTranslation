#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int max_h;
  cin >> max_h;

  int count = 1;

  for (int i = 1; i < N; i++) {
    int h;
    cin >> h;

    if (h >= max_h) {
      count++;
      max_h = h;
    }
  }

  cout << count << endl;
}