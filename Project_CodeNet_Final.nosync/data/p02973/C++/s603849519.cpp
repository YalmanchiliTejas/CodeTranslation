#include <bits/stdc++.h>

#ifdef LOCAL
  #include <contest/local.hpp>
#else
  #define LOG(...) do {} while (false)
#endif

#define REP(i,n) for (decay_t <decltype (n)> i = 0, i ## __len = (n); i < i ## __len; ++ i)
#define ALL(x) (x).begin (), (x).end ()

using namespace std;

auto main () -> int
{
  cin.tie (nullptr);
  ios::sync_with_stdio (false);

  unsigned n;
  cin >> n;

  multiset <int> group;
  vector <int> a;

  REP (i, n)
  {
    int value;
    cin >> value;
    a.emplace_back (value);
  }

  auto i = a.begin ();
  group.insert (* i);

  for (++ i; i != a.end (); ++ i)
  {
    auto && elem = * i;
    auto ite = group.lower_bound (elem);
    if (ite != group.begin ())
    {
      -- ite;
      group.erase (ite);
    }
    group.insert (elem);
#ifdef LOCAL
    cerr << "dump: ";
    for (auto && eeeeee : group)
    {
      cerr << eeeeee << " ";
    }
    cerr << endl;
#endif
  }
  cout << group.size () << endl;
}

