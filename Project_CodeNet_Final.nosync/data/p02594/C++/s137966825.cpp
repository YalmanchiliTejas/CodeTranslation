#define errOut(s) \
  { std::cerr << __LINE__ << ":" << #s << ":" << (s) << std::endl; }

#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
//#include <boost/multi_array.hpp>
//#include <boost/optional.hpp>
//#include <boost/range/adaptors.hpp>
//#include <boost/range/algorithm.hpp>
//#include <boost/range/irange.hpp>
#pragma clang diagnostic pop

using namespace std;

static std::string const YES = "Yes";
static std::string const NO = "No";

bool solve(int64_t x) { return x >= 30; }

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int64_t x;
  std::cin >> x;
  auto const res = solve(x);
  std::cout << (res ? YES : NO) << std::endl;
  return 0;
}
