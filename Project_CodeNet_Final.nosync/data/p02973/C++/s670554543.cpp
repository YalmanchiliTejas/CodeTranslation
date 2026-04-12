#include <bits/stdc++.h>
using namespace std;

const bool DEBUG = false;

int N;
vector<long long> A;

vector<long long> dp;

void input() {
  cin >> N;
  A = vector<long long>(N);
  for (size_t i = 0; i < N; i++) cin >> A[i];
}

long long lis(const vector<long long>& x) {
  // longest increasing subsequence
  dp = vector<long long>(x.size(), 1e18);
  for (size_t i = 0; i < x.size(); i++) {
    decltype(dp)::iterator itr = lower_bound(dp.begin(), dp.end(), x[i]);
    *itr = x[i];
  }
  return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), 1e18));
}

long long lnis(const vector<long long>& x) {
  // longest non-increasing subsequence
  auto y = x;
  reverse(y.begin(), y.end());
  dp = vector<long long>(x.size(), 1e18);
  for (size_t i = 0; i < x.size(); i++) {
    decltype(dp)::iterator itr = upper_bound(dp.begin(), dp.end(), y[i]);
    *itr = y[i];
  }
  return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), 1e18));
}

int main(int argc, char const* argv[]) {
  input();
  cout << lnis(A) << endl;
  return 0;
}
