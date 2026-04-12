#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  vector<int> v;
  for (int i = 0; i < N; i++) {
    auto it = upper_bound(v.begin(), v.end(), -A[i]);
    if (it == v.end())
      v.push_back(-A[i]);
    else
      *it = -A[i];
  }

  cout << v.size() << endl;
}
