#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

int main(void) {
  long N;
  cin >> N;
  vector<long> Hs(N);
  rep (i, N) cin >> Hs[i];
  long highest = 0;
  long result = 0;
  rep (i, N) {
    if (highest <= Hs[i]) {
      highest = Hs[i];
      result++;
    }
  }
  cout << result << endl;
  return 0;
}
