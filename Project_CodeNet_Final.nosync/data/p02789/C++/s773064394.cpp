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
#include <boost/math/common_factor.hpp>
#include <boost/algorithm/string.hpp>

#define REP(i, N) for(int i=0; i<(N); i++)
#define REC(f, ...) (void)0; const auto f = [&](const auto f, __VA_ARGS__)
using namespace std;
using namespace boost::math;

using ll = long long;
namespace bst = boost;
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
  in<int> A, B;


  return (A == B) ? "Yes" : "No";
}

template<typename T> void plot(const T& func) { cout << func() << endl; }
template<> void plot<void()>(void(&func)()) { func(); }

int main() {
  plot(solve);

  return 0;
}
