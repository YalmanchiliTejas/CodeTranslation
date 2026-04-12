#include "bits/stdc++.h"
using namespace std;

#define int long long

int f(vector<int> a , vector<int> p, int n, int x){
  if (n == 0)
    return x <= 0 ? 0 : 1;
  else if (x <= 1 + a[n - 1])
    return f(a, p, n-1,x-1);
  else
    return p[n-1] + 1 + f(a, p,n-1,x-2-a[n-1]);
}

signed main(void)
{
  int num; // num
  num = 0; // count, result
  // num = numeric_limits<int>::min(); // max
  // num = numeric_limits<int>::max(); // min
  int n;
  int x;

  vector<int> a;
  vector<int> p;

  cin >> n >> x;
  a.push_back(1);
  p.push_back(1);

  for (int i = 0; i < n; ++i){
    a.push_back(2 * a.back() + 3);
    p.push_back(2 * p.back() + 1);
  }

  cout << f(a,p,n,x) << endl;
  return 0;
}
