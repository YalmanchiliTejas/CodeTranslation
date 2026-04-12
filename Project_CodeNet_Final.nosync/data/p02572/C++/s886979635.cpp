//
//  atcoder.cpp
//
//
///
#include <bits/stdc++.h>
#include <boost/optional.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/multi_array.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/icl/interval_map.hpp>

#define REPI(i, S, N) for(int i=int(S); i<int(N); i++)
#define REP(i, N) REPI(i, 0, N)
#define REC(f, ...) (void)0; const auto f = [&](const auto f, __VA_ARGS__)
using namespace std;
using namespace boost::integer;

using ll = long long;
namespace bst = boost;
namespace icl = boost::icl;
template<typename T> class in {
    T value;
public:
    in() { cin >> value; }
    operator const T&() const { return value; }
    operator T&() { return value; }
    in& operator=(T source) { value = source; return *this; }
};
template<> class in<string> : public string {
public:
    in() { cin >> *this; }
};
template<class T> class inseq : public T {
public:
    template<typename... Arg> inseq(Arg... arg) : T(forward<Arg>(arg)...) { for (auto&& i : *this) cin >> i; }
};
template<class T> using invec = inseq<vector<T>>;

auto solve() {
  in<ll> N;
  invec<ll> A(N);


  
  ll nowr = A[0], r = 0;
  for (int i = 1; i < N; i++) {
    r = (r + nowr * A[i] % 1000000007) % 1000000007;
    nowr = (nowr + A[i]) % 1000000007;
  }
  return r;
}

template<typename T> void plot(const T& func) { cout << setprecision(9) << func() << endl; }
template<> void plot<void()>(void(&func)()) { func(); }

int main() {
  plot(solve);

  return 0;
}

