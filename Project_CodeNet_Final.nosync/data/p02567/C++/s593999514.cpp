#include <bits/stdc++.h>

template <typename T>
T BinarySearch(T ok, T ng, std::function<bool(T)> pred) {
  if constexpr (std::is_integral<T>::value) {
    while ((ok > ng ? ok - ng : ng - ok) > 1) {
      T mid = ok + (ng - ok) / 2;
      (pred(mid) ? ok : ng) = mid;
    }
    return ok;
  }
  if constexpr (std::is_floating_point<T>::value) {
    for (int i = 0; i < 200; ++i) {
      T mid = (ok + ng) / 2;
      (pred(mid) ? ok : ng) = mid;
    }
    return ok;
  }
}

template <typename T, typename = void>
struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
                                  decltype(std::end(std::declval<T>()))>>
    : std::true_type {};

template <typename T, typename = void>
struct is_pair : std::false_type {};
template <typename T>
struct is_pair<T, std::void_t<decltype(std::declval<T>().first),
                              decltype(std::declval<T>().second)>>
    : std::true_type {};

template <typename T>
void debug(const T& v) {
  if constexpr (is_pair<T>::value) {
    std::cerr << "{";
    debug(v.first);
    std::cerr << ", ";
    debug(v.second);
    std::cerr << "}";
  } else if constexpr (is_iterable<T>::value &&
                       !std::is_same<T, std::string>::value) {
    std::cerr << "{";
    for (auto it = std::begin(v); it != std::end(v); ++it) {
      if (it != std::begin(v)) std::cerr << ", ";
      debug(*it);
    }
    std::cerr << "}";
  } else {
    std::cerr << v;
  }
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  debug(value);
  std::cerr << ", ";
  debug(args...);
}
#if DEBUG
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define rd(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);
#define ints(...) rd(int, __VA_ARGS__);
#define strings(...) rd(string, __VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  if constexpr (std::is_same<T, bool>::value) {
    std::cout << (value ? "Yes" : "No");
  } else {
    std::cout << value;
  }
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  write_to_cout(value);
  std::cout << ' ';
  write_to_cout(args...);
}
#define wt(...)                 \
  do {                          \
    write_to_cout(__VA_ARGS__); \
    cout << '\n';               \
  } while (0)

#define all(x) (x).begin(), (x).end()

#define rep_dispatch(_1, _2, _3, name, ...) name

#define rep3(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep2(_loop_variable_, n)
#define rep(...) rep_dispatch(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep3(i, a, b) for (int i = (int)(b)-1; i >= a; --i)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep1(n) rrep2(_loop_variable_, n)
#define rrep(...) rep_dispatch(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (T& vi : v) is >> vi;
  return is;
}

template <typename T, typename U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T, typename U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
bool chmin(T& a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
int sz(const T& v) {
  return v.size();
}

template <typename T>
int popcount(T i) {
  return std::bitset<std::numeric_limits<T>::digits>(i).count();
}

#include <boost/hana/functional/fix.hpp>
const auto& Fix = boost::hana::fix;

using ll = long long;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  SegmentTree(int size, Operation operation, T identity = T())
      : operation_(operation), identity_(identity) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
  }
  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = operation_(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      if (begin <= cbegin && cend <= end) {
        return v_[index];
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(rec(cbegin, cmid, index * 2 + 1),
                        rec(cmid, cend, index * 2 + 2));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

 private:
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
};

using namespace std;

int main() {
  ints(n, q);
  V<int> a(n);
  cin >> a;
  SegmentTree<int> tree(
      n, [](int a, int b) { return max(a, b); }, numeric_limits<int>::min());
  rep(i, n) tree.Set(i, a[i]);
  rep(q) {
    ints(t, x, v);
    if (t == 1) {
      tree.Set(x - 1, v);
    } else if (t == 2) {
      wt(tree.Aggregate(x - 1, v));
    } else {
      if (tree.Aggregate(x - 1, n) < v) {
        wt(n + 1);
      } else {
        wt(BinarySearch<int>(
            n, x - 2, [&](int y) { return tree.Aggregate(x - 1, y) >= v; }));
      }
    }
  }
}
