#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  vector<int> H(N + 1);

  for (int i = 1; i < N + 1; i++) {
    cin >> H[i];
  }

  int ans = 1;
  int max = H[1];

  for (int i = 2; i < N + 1; i++) {
    if (H[i] >= max) {
      max = H[i];
      ans++;
    }
  }

  cout << ans << "\n";
  return 0;
}
