#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using namespace std;


void solve(long long N, std::vector<long long> A){
  multiset<long long> s;
  s.insert(A[0]);
  for (int i = 1; i < N; i++) {
    auto it = s.lower_bound(A[i]);
    if (it == s.begin()) {
      s.insert(A[i]);
    } else {
      s.erase(--it);
      s.insert(A[i]);
    }
  }
  std::cout << s.size() << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  std::vector<long long> A(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
