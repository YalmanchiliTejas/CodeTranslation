#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using i64 = long long;

int main() {
  i64 N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  multiset<int> st;
  i64 res = 0;
  for (int i = 1; i <= N; i++) {
    if (!st.empty() && *st.begin() < A[i]) {
      auto itr = st.lower_bound(A[i]);
      itr--;
      st.erase(itr);
      st.insert(A[i]);
    } else {
      res++;
      st.insert(A[i]);
    }
  }
  cout << res << endl;
}