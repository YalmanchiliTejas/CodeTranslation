#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int N, H;
  cin >> N;
  int M = 0;
  int ret = 0;
  for (int i=0; i<N; i++) {
    cin >> H;
    if (M <= H) {
      ret++;
      M = H;
    }
  }
  cout << ret << endl;
}