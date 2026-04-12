#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H;
  while (cin >> N) {
    int maxH = 0, num = 0;
    while (N--) {
        cin >> H;
        if (H >= maxH) {
            ++num;
            maxH = H;
        }
    }
    cout << num << endl;
  }
  return 0;
}
