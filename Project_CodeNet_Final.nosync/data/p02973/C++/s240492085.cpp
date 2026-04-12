#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
typedef signed long long ll;

mt19937 mt(time(nullptr));
// uniform_int_distribution< int > rand_int(0, 10) // rand[0, 10] inclusive

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed;
  ul n;
  cin >> n;
  vector< ll > c(0);
  for (ul i=0; i<n; ++i) {
    ll a;
    cin >> a;
    a *= -1;
    if (c.size() == 0) {
      //cerr << "push_back " << a << endl;
      c.push_back(a);
      continue;
    }
    if (c[c.size()-1] <= a) {
      //cerr << "push_back " << a << endl;
      c.push_back(a);
      continue;
    }
    ul idx = upper_bound(c.begin(), c.end(), a) - c.begin();
    //cerr << idx << " " << c[idx] << "->" << a << endl;
    c[idx] = a;
  }
  cout << c.size() << endl;
  return 0;
}
