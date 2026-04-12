#include <iostream>
#include <vector>

using namespace std;

vector<long long> lengths(51);
vector<long long> patties(51);

long long travel(int level, long long eat, long long ans) {
  if (eat == lengths[level]) return ans + patties[level];
  if (eat <= 1) return ans;
  if (eat < lengths[level - 1] + 1) return travel(level - 1, eat - 1, ans);
  if (eat == lengths[level - 1] + 1) return ans + patties[level - 1];
  if (eat == lengths[level - 1] + 2) return ans + patties[level - 1] + 1;
  if (eat > lengths[level - 1] + 2) return travel(level - 1, eat - lengths[level - 1] - 2, ans + patties[level - 1] + 1);
}

int main() {
  int N;
  long long X;
  cin >> N >> X;

  lengths[0] = 1;
  patties[0] = 1;
  for (int i = 0; i < N; ++i) {
    lengths[i + 1] = 3 + 2 * lengths[i];
    patties[i + 1] = 1 + 2 * patties[i];
  }

  cout << travel(N, X, 0) << endl;
  return 0;
}