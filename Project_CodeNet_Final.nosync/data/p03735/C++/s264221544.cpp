#define STOPIT
#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_a_genius = 0; ngtkana_is_a_genius < int(n); ngtkana_is_a_genius++)
#define rep(i, begin, end) for (int i = int(begin); (i) < int(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto cmx = [](auto& a, auto b){ if (a < b) {a = b; return true;} return false; };
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#ifndef STOPIT
#define debug(...)\
  do {\
    std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_impl(__VA_ARGS__);\
    std::cerr << std::noboolalpha;\
  } while (false)
#else
#define debug(...) {}
#endif

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& tuple_input_impl(std::istream& os, Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { (void)std::initializer_list<int>{((void)(os >> std::get< Inds >(tuple)), 0)...}; return os; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& operator>> (std::istream& os, Tuple<Args...>& tuple)
  { return tuple_input_impl(os, tuple, std::index_sequence_for<Args...>()); }

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& tuple_output_impl(std::ostream& os, const Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { os << "("; (void)std::initializer_list<int>{((void)(os << (Inds > 0 ? "," : "") << std::get< Inds >(tuple)), 0)...}; return os << ")"; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& operator<< (std::ostream& os, const Tuple<Args...>& tuple)
 { return tuple_output_impl(os, tuple, std::index_sequence_for<Args...>()); }


template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
 os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}


template < std::size_t I, typename Container,
  typename Value = typename std::tuple_element_t< I, typename Container::value_type >>
inline auto project(Container const& v) {
  std::vector< Value > ret(v.size());
  std::transform(v.begin(), v.end(), ret.begin(), [](auto&& t){ return std::get< I >(t); });
  return ret;
}

template < class Container, class T = typename Container::value_type >
auto coenumerate(Container const& v) {
  auto n = v.size();
  std::vector< std::pair< T, int >> ret(n);
  for (std::size_t i = 0; i < n; i++)
    { ret.at(i) = {v.at(i), i}; }
  return ret;
}

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  std::vector<std::pair<lint,lint>>data(n);
  rep(i,0,n) {
    lint x, y; std::cin >> x >> y;
    if (x > y) std::swap(x,y);
    data.at(i) = {x,y};
  }
  auto x = project<0>(data);
  auto y = project<1>(data);

  auto basic_ans = [&] {
    auto xminmax = std::minmax_element(all(x));
    auto yminmax = std::minmax_element(all(y));
    lint xmin = *xminmax.first;
    lint xmax = *xminmax.second;
    lint ymin = *yminmax.first;
    lint ymax = *yminmax.second;
    lint dx = xmax - xmin;
    lint dy = ymax - ymin;
    lint ans = dx*dy;
    debug(xmin,xmax,ymin,ymax);
    debug(dx,dy,ans);
    return ans;
  }();
  debug(basic_ans);

  auto z = [&]{
    auto ex = coenumerate(x);
    auto ey = coenumerate(y);
    std::vector<std::pair<lint,int>> z;
    z.insert(z.end(), all(ex));
    z.insert(z.end(), all(ey));
    std::sort(all(z));
    return z;
  }();
  debug(z);

  auto d = [&] {
    lint ans = std::numeric_limits<lint>::max();
    std::vector<int> mul(n,0);
    int kind = 0;
    int N = 2 * n;
    int r = 0;
    rep(l,0,N) {
      lint x = z.at(l).first;
      while (r < N && kind < n) {
        lint y, i; std::tie(y,i) = z.at(r);
        if (!mul.at(i)) kind++;
        mul.at(i)++;
        r++;
      }
      if (r == N && kind < n) break;

      lint y = z.at(r-1).first;
      lint now = y - x;
      debug(l,r,x,y,now);
      cmn(ans, now);

      lint i = z.at(l).second;
      mul.at(i)--;
      if (!mul.at(i)) kind--;
    }
    return ans;
  }();
  debug(d);

  lint xmin = *std::min_element(all(x));
  lint ymax = *std::max_element(all(y));
  lint additional_ans = (ymax-xmin) * d;
  debug(basic_ans, additional_ans);
  lint ans = std::min(basic_ans, additional_ans);
  std::cout << ans << std::endl;
  return 0;
}