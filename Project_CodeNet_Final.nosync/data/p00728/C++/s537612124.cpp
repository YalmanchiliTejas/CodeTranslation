#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define lout cout
#else
stringstream devnull;
#define lout devnull
#endif
template <class C>
inline void vcin(C &a);
template <class C>
inline void vcout(const C a, const string separate = "\n");

int main()
{
  while (true)
  {
    int n;
    cin >> n;
    if (n == 0)
    {
      break;
    }
    vector<int> s(n);
    vcin(s);
    sort(s.begin(), s.end());
    s.erase(s.begin());
    s.pop_back();
    cout << accumulate(s.begin(), s.end(), 0) / s.size() << endl;
  }
  return 0;
}

template <class C>
inline void vcin(C &c)
{
  for (auto &a : c)
  {
    cin >> a;
  }
}
template <class C>
inline void vcout(const C c, const string separate)
{
  for (auto it = c.begin(); it != c.end(); it++)
  {
    if (it != c.begin())
      cout << separate;
    cout << *it;
  }
}

