#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int n;
  multiset<int> s;

  cin >> n;
  rep(i, n)
  {
    int x;
    cin >> x;
    auto tmp = s.lower_bound(x);
    if (tmp != s.begin())
    {
      s.erase(--tmp);
    }
    s.insert(x);
  }

  cout << s.size() << endl;
  return 0;
}
