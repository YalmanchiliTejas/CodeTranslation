#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n, input;

  while (true) {
    cin >> n;
    if (n == 0) { break; }

    vector<int> scores;
    for (int i = 0; i < n; i++) {
      cin >> input;
      scores.push_back(input);
    }

    cout << (accumulate(scores.begin(), scores.end(), 0) - *max_element(scores.begin(), scores.end()) - *min_element(scores.begin(), scores.end())) / (n - 2) << endl;
  }

  return 0;
}