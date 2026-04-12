#include <iterator>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
int main(int argc, char **argv) {
  int N;
  cin >> N;

  vector<int> H;
  H.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  int ans = 1;
  for (int i = 1; i < N; i++) {
    int j = i-1;
    while (j >= 0 && H[i] >= H[j])
      --j;

    if (j < 0)
      ++ans;
  }
  cout << ans << endl;
  return 0;
}