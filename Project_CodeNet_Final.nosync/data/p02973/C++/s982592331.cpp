#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1000000001;
vector<int> lis(vector<int> ary) {
    vector<int> dp(ary.size(), INF);
    for (const auto& x : ary) {
        *upper_bound(dp.begin(), dp.end(), x) = x;
    }
    return vector<int>(dp.begin(), lower_bound(dp.begin(), dp.end(), INF));
}

int main()
{
  int N; cin >> N;
  vector<int> A(N, 0);
  for (int i = 0; i < N; i++) { cin >> A[i]; A[i] *= -1; }
  cout << lis(A).size() << endl;

  return 0;
}