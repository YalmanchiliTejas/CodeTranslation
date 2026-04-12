#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void showIntArray(int a[], int n) {
  for (int i=0; i<n; i++) {
    cout << a[i] << ' ';
  } cout << endl;
}

int main() {
  int N, H[10000], c=0, flag;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> H[i];
    flag = 1;
    for (int j=0; j<i; j++) {
      if (H[i] < H[j]) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}