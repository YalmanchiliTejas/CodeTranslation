#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// #include "prettyprint.hpp"

int main() {
  int N;
  cin >> N;
  long A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  multiset<long, less<long>> bst;

  bst.insert(A[0]);
  for (int i = 1; i < N; i++) {
    if (A[i] <= *bst.begin()) {
      bst.insert(A[i]);
    } else {
      set<long>::iterator it = bst.lower_bound(A[i]);
      it--;
      // cout << *it << endl;
      // cout << "low of " << A[i] << " : " << *it << endl;
      bst.erase(it);
      bst.insert(A[i]);
    }
    // cout << bst << endl;
  }

  cout << bst.size() << endl;

  return 0;
}