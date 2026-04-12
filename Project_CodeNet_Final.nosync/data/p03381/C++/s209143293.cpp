#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <limits>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <numeric>
#include <tuple>

constexpr long long mod = static_cast<long long>(1e9 + 7);

struct Data
{
  int _1;
  int _2;
};

int main() {
  int N;
  std::cin >> N;
  std::vector<Data> vec(N);
  for(int i = 0; i < N; ++i)
  {
    std::cin >> vec[i]._1;
    vec[i]._2 = i;
  }
  std::sort(begin(vec), end(vec), [](auto& v, auto& u){ return v._1 < u._1;});
  std::vector<int> ans(N);
  for(int i = 0; i < N; ++i)
  {
    if(i<N/2)
      ans[vec[i]._2] = vec[N/2]._1;
    else
      ans[vec[i]._2] = vec[N/2 - 1]._1;
  }
  for(auto& x: ans)
    std::cout << x << "\n";
  std::cout  << std::flush;
  return 0;
}
