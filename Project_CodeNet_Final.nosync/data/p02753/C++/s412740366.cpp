#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define G(x, i) get<i>(x)
#define BITL(x, i) ((x) << (i))
#define BITR(x, i) ((x) >> (i))

using namespace std;

typedef tuple<int, int> i2;
typedef tuple<int, int, int> i3;
typedef tuple<int, int, int, int> i4;
typedef vector<int> vi;
typedef vector<i2> vi2;
typedef vector<i3> vi3;
typedef vector<vi> v2i;
typedef long long ll;
typedef tuple<ll, ll> l2;
typedef tuple<ll, ll> l3;
typedef vector<ll> vl;
typedef vector<l2> vl2;

int main() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (char c : s)
    if (c == 'A')
      ++a;
    else
      ++b;
  if (a && b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}