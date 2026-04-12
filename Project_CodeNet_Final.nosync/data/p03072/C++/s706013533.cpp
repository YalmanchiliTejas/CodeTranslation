#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  vector<int> h(N);
  for (size_t i = 0; i < N; i++) {
    cin >> h[i];
  }

  int result = 0;
  int max = 0;
  for (size_t i = 0; i < N; i++) {
    if (h[i] >= max) {
      result++;
      max = h[i];
    }
  }
  cout << result << endl;
}