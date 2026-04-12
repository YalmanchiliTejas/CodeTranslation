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
vec2d<T> makeVec2d(const int n1, const int n2) {
  return vec2d<T>(n1, vec<T>(n2));
}

template<class T>
vec2d<T> makeVec2d(const int n1, const int n2, const T initValue) {
  return vec2d<T>(n1, vec<T>(n2, initValue));
}


#define FOR(i, n) for (int i = 0; i < (n); ++i)


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


const int MOD = (int)1e9 + 7;

void solve(istream& in, ostream& out) {
  auto num = next<string>(in);
  auto d = next<int>(in);

  vec2d<int> dp = makeVec2d<int>(d, 2);
  vec2d<int> nxt = makeVec2d<int>(d, 2);

  int dd = num[0] - '0';
  FOR(i, dd) {
    dp[i % d][0] += 1;
  }
  dp[dd % d][1] += 1;

  FOR(i, num.length()) if (i) {
    FOR(j, d) {
      FOR(w, 2) {
        if (!dp[j][w]) continue;
        if (w == 1) {
          // continue prefix
          FOR(nd, num[i] - '0' + 1) {
            int newJ = j + nd;
            newJ %= d;
            (nxt[newJ][nd == num[i] - '0' ? 1 : 0] += dp[j][w]) %= MOD;
          }
        } else {
          FOR(nd, 10) {
            int newJ = j + nd;
            newJ %= d;
            (nxt[newJ][0] += dp[j][w]) %= MOD;
          }
        }
      }
    }
    dp = nxt;
    nxt = makeVec2d<int>(d, 2, 0);
  }

  int res = 0;
  FOR(j, 2) {
    res += dp[0][j];
    if (res >= MOD) {
      res -= MOD;
    }
  }
  --res;
  if (res < 0) res += MOD;
  out << res << "\n";
}

//#include <fstream>


int main() {
//  ifstream fin("bridges.in");
//  ofstream fout("bridges.out");
    solve(cin, cout);
//  solve(fin, fout);
    return 0;
}

