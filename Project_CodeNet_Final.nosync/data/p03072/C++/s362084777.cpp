#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> H(N);
  for_each(H.begin(), H.end(), [](int& e) { cin >> e; });
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (all_of(H.begin(), H.begin() + i, [&](int x) { return x <= H[i]; })) ans++;
  }
  cout << ans << endl;
  return 0;
}
