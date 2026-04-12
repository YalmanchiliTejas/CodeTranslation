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


constexpr int64_t INF = numeric_limits<int64_t>::max() / 2;

struct SegmentTree {
  vec<int64_t> tmax, tadd;
  int n;

  SegmentTree(int n_) : n(n_) {
    tmax = vec<int64_t>(4 * n);
    tadd = vec<int64_t>(4 * n);
  }

  void push(int v) {
    if (tadd[v] != 0) {
      if (2 * v < tmax.size()) {
        tadd[2 * v] += tadd[v];
        tmax[2 * v] += tadd[v];
      }
      if (2 * v + 1 < tmax.size()) {
        tadd[2 * v + 1] += tadd[v];
        tmax[2 * v + 1] += tadd[v];
      }
      tadd[v] = 0;
    }
  }

  void update(int v) {
    tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
  }

  void internalAdd(int v, int left, int right, int rangeLeft, int rangeRight, int64_t val) {
    if (left >= rangeRight || right <= rangeLeft) {
      return;
    }
    push(v);
    if (rangeLeft >= left && rangeRight <= right) {
      tadd[v] += val;
      tmax[v] += val;
      return;
    }
    int middle = (rangeLeft + rangeRight) / 2;
    internalAdd(v * 2, left, right, rangeLeft, middle, val);
    internalAdd(v * 2 + 1, left, right, middle, rangeRight, val);
    update(v);
  }

  int64_t internalGetMax(int v, int left, int right, int rangeLeft, int rangeRight) {
    if (left >= rangeRight || right <= rangeLeft) {
      return -INF;
    }
    push(v);
    if (rangeLeft >= left && rangeRight <= right) {
      return tmax[v];
    }
    int middle = (rangeLeft + rangeRight) / 2;
    int64_t res = internalGetMax(v * 2, left, right, rangeLeft, middle);
    res = max(res, internalGetMax(v * 2 + 1, left, right, middle, rangeRight));
    return res;
  }

  void add(int le, int ri, int64_t val) {
    internalAdd(1, le, ri + 1, 0, n, val);
  }

  int64_t getMax(int le, int ri) {
    return internalGetMax(1, le, ri + 1, 0, n);
  }
};

void solve(istream& in, ostream& out) {
  auto n = next<int>(in);
  auto m = next<int>(in);
  vec<vec<pair<int, int>>> events(n + 2);
  FOR(i, m) {
    auto l = next<int>(in);
    auto r = next<int>(in) + 1;
    auto a = next<int>(in);
    events[l].push_back({l, a});
    events[r].push_back({l, -a});
  }
  SegmentTree stree(n + 2);
  int64_t res = 0;
  FOR(i, n) {
    for (auto& p : events[i + 1]) {
      stree.add(0, p.first - 1, p.second);
    }
    auto dp = stree.getMax(0, i);
    res = max(res, dp);
    stree.add(i + 1, i + 1, dp);
  }
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

