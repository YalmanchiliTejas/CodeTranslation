#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int max_height = 0;
  int viewable = 0;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    if (h >= max_height) {
      ++viewable;
      max_height = h;
    }
  }
  cout << viewable << endl;
}
