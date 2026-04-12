#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/math/common_factor.hpp>

#define rep_ui(k,n)      for(ui  i = (k); i < (n); ++i)
#define rep_si(k,n)      for(int i = (k); i < (n); ++i)
#define rep_ul(k,n)      for(ul  i = (k); i < (n); ++i)
#define rep_sl(k,n)      for(ll  i = (k); i < (n); ++i)
#define rep_ui_down(k,n) for(ui  i = (k); i > (n); --i)
#define rep_si_down(k,n) for(int i = (k); i > (n); --i)
#define rep_ul_down(k,n) for(ul  i = (k); i > (n); --i)
#define rep_sl_down(k,n) for(ll  i = (k); i > (n); --i)

#define rep_uj(k,n)      for(ui  j = (k); j < (n); ++j)
#define rep_sj(k,n)      for(int j = (k); j < (n); ++j)
#define rep_uj_down(k,n) for(ui  j = (k); j > (n); --j)
#define rep_sj_down(k,n) for(int j = (k); j > (n); --j)

#define rep(k,n)         rep_ui(k,n)

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vc)
{
#ifdef BOOST_RANGE_ALGORITHM_FOR_EACH_HPP_INCLUDED
  boost::for_each(vc, [&os](T value) {
#else
  std::for_each(vc.begin(), vc.end(), [&os](T value) {
#endif
    os << value << '\n';
    });
  return os;
}

template<class T1, class T2>
inline
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p)
{
  return os << p.first << ' ' << p.second;
}

void solve(void)
{
  using std::string;
  using std::vector;
  using std::map;
  using std::pair;
  using std::cin;
  //string S{}; std::cin >> S;
  ui N{}; cin >> N;
  vector<ull> v(N);
  rep(0, N) cin >> v[i];
  ull sum{};
  ull highest{};
  boost::for_each(v, [&sum, &highest](auto v) {
    if (v >= highest)
    {
      ++sum;
      highest = v;
    }
    });

  using std::cout;
  cout << sum << '\n';
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
