#include <iostream>
#include <set>
#include <vector>
using namespace std;
int N, t_max = 0, ans = 0;
multiset<int> t;
vector<int> divisor;
int main() {
  // Input
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    t.insert(tmp);
  }
  t_max = *(--t.end());
  // Divisor
  for (int i = 1; i <= t_max; i++) {
    if (t_max % i == 0) {
      divisor.push_back(i);
    }
  }
  // Answer
  auto ti = t.begin();
  for (int i = 0; i < divisor.size() && ti != t.end();) {
    if (divisor[i] < *ti) {
      i++;
      continue;
    }
    ans += divisor[i] - *ti;
    ti++;
  }

  cout << ans << endl;

  return 0;
}
