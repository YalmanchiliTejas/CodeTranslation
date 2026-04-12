#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int ans = 0;
  int h = 0;
  for (int i = 0; i < N; i++) {
    h = max(H[i], h);
    if (h == H[i]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}