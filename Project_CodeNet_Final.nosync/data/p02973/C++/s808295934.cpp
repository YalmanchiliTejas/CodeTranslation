#include <iomanip>
#include <iostream>
#include <set>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  multiset<int> mapA;
  rep(i, N) {
    int A;
    cin >> A;
    auto itr = mapA.lower_bound(A);
    if (itr != mapA.begin()) {
      --itr;
      mapA.erase(itr);
    }
    mapA.emplace(A);
  }

  cout << mapA.size() << endl;
  return 0;
}
