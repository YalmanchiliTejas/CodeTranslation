#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <queue>
#include <cmath>
#include <numeric>
#include <map>
#define REP(i, N) for(int i=0; i<N; i++)
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int N;

	cin >> N;
  vector<int> A(N);
  multiset<int> num;
  
  for (auto& i : A) {
    cin >> i;
  }
  
  num.insert(*A.begin());
  int r = 1;

  
  for (auto it = A.begin() + 1; it != A.end(); ++it) {
    auto nit = num.lower_bound(*it);
    if (nit != num.begin()) {
      --nit;
      num.erase(nit);
    }
    num.insert(*it);
  }
  
  cout << num.size() << endl;

	return 0;
}
