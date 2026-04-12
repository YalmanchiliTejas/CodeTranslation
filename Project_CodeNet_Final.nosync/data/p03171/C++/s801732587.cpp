#define NDEBUG
NDEBUG


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <queue>
#include <random>


using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;


template<class T>
vec2d<T> makeVec2d(const int n1, const int n2, const T initValue) {
  return vec2d<T>(n1, vec<T>(n2, initValue));
}


// TC_REMOVE_BEGIN
/// caide keep
bool __hack = std::ios::sync_with_stdio(false);
/// caide keep
auto __hack1 = cin.tie(nullptr);
// TC_REMOVE_END


// Section with adoption of array and vector algorithms.


//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//
//template <class T> using StdTree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        
    };

    
    /// caide keep
    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}

template<class T>
vector<T> next_vec(istream& in, size_t n) {
  vector<T> ret(n);
  for (size_t i = 0; i < n; ++i) {
    ret[i] = next<T>(in);
  }
  return ret;
}


void solve(istream& in, ostream& out) {
  auto n = next<int>(in);
  auto a = next_vec<int64_t>(in, n);
  vec2d<int> u = makeVec2d<int>(n, n, 0);
  vec2d<int64_t> dp = makeVec2d<int64_t>(n, n, 0);

  function<int64_t(int, int)> rec = [&] (int le, int ri) -> int64_t {
    int eaten = le + (n - 1 - ri);
    if (le == ri) {
      if (eaten % 2 == 0) {
        return a[le];
      } else {
        return -a[le];
      }
    }
    if (u[le][ri]) {
      return dp[le][ri];
    }

    auto& res = dp[le][ri];
    u[le][ri] = 1;

    if (eaten % 2 == 0) {
      auto cutLeft = a[le] + rec(le + 1, ri);
      auto cutRight = a[ri] + rec(le, ri - 1);
      res = max(cutLeft, cutRight);
      return res;
    } else {
      auto cutLeft = -a[le] + rec(le + 1, ri);
      auto cutRight = -a[ri] + rec(le, ri - 1);
      res = min(cutLeft, cutRight);
      return res;
    }
  };

  out << rec(0, n-1) << "\n";

}

//#include <fstream>


int main() {
//  ifstream fin("bridges.in");
//  ofstream fout("bridges.out");
    solve(cin, cout);
//  solve(fin, fout);
    return 0;
}

