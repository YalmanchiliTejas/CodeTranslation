#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;
  int H[110];
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> H[i];

  int hotel = 1;
  int max = H[0];
  for (int i = 1; i < N; ++i) {
    if (H[i] >= max) {
      ++hotel;
      max = H[i];
    }
  }
  cout << hotel << endl;
}
