#include <iomanip>
#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  map<int, int> mapA;
  rep(i, N) {
    int A;
    cin >> A;
    auto itr = mapA.lower_bound(A);
    if (itr != mapA.begin()) {
      --itr;
      itr->second--;
      if (itr->second == 0) mapA.erase(itr);
    }
    mapA[A] += 1;
  }

  int answer = 0;
  for (auto& A : mapA) {
    answer += A.second;
  }
  cout << answer << endl;
  return 0;
}
