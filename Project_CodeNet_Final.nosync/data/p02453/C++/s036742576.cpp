#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> parse() {
  int n, x;
  cin >> n;
  vector<int> A;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    A.push_back(x);
  }
  return A;
}

int main() {
  auto A = parse();
  int k;
  cin >> k; // skip q
  while (cin >> k)
    cout << distance(A.begin(), lower_bound(A.begin(), A.end(), k)) << endl;
}
