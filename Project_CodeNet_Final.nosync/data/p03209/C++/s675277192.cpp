#include <bits/stdc++.h>
#define rep(i,n)    for (decay_t <decltype (n)> i = 0, i ## __len = (n); i < i ## __len; ++ i)
#define FOR(i,b,e)  for (common_type_t <decltype (b), decltype (e)> i = (b), i ## __end = (e); i < i ## __end; ++ i)
#define FORR(i,b,e) for (common_type_t <decltype (b), decltype (e)> i = (e), i ## __begin = (b); i -- > i ## __begin;)
#define ALL(x)      begin (x), end (x)
using namespace std;

auto main () -> int
{
  cin.tie (nullptr);
  ios::sync_with_stdio (false);

  size_t N;
  int64_t X;
  cin >> N >> X;

  array <int64_t, 51> height;
  height [0] = 1;
  FOR (i, 1, height.size ())
  {
    height [i] = height [i - 1] * 2 + 3;
  }

  map <pair <size_t, int64_t>, int64_t> memo;
  auto eat = [&] (auto self, size_t n, int64_t x) -> int64_t
  {
    assert (x > 0);
    x = min (x, height [n]);
    {
      auto ite = memo.find (make_pair (n, x));
      if (ite != memo.end ())
      {
        return ite -> second;
      }
    }
    auto middle = height [n] / 2 + 1;
    if (n == 0)
    {
      return 1;
    }
    if (x == 1)
    {
      return memo [make_pair (n, x)] = 0;
    }
    else if (x < middle)
    {
      return memo [make_pair (n, x)] = self (self, n - 1, x - 1);
    }
    else if (x == middle)
    {
      return memo [make_pair (n, x)] = self (self, n - 1, x - 1) + 1;
    }
    else
    {
      return memo [make_pair (n, x)] = self (self, n - 1, height [n - 1]) + 1 + self (self, n - 1, x - middle);
    }
  };

  cout << eat (eat, N, X) << endl;
}
