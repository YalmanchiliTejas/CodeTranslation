#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll A = a * x + b * y;
  ll B;
  if (x < y) B = c * x * 2 + (y - x) * b;
  else if(x > y) B = c * y * 2 + (x - y) * a;
  else B = c * y * 2;
  ll C = c * max(x, y) * 2;
  cout << min(C, min(A, B)) << endl;
  

  return 0;
}