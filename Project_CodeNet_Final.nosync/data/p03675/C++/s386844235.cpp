#include <bits/stdc++.h>
 
#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
 
using namespace std;
 
typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;
 
template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
 
int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  while (cin >> n) {
    vector<int> a(n);
    each (i, a) cin >> i;
    list<int> x;
    int cnt = 0;
    each (i, a) {
      if (cnt++ % 2) x.push_front(i);
      else x.push_back(i);
    }
    if (n % 2) reverse(x.begin(), x.end());
    bool f = false;
    each (i, x) {
      if (f) cout << ' ';
      f = true;
      cout << i;
    }
    cout << endl;
  }
  
  return 0;
}
