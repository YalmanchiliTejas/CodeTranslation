#include <iostream>
using namespace std;

int main() {
  int N, H, max_hight = 0, count = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> H;
    if (H >= max_hight) {
      max_hight = H;
      count++;
    }
  }
  cout << count << endl;
  return 0;
}