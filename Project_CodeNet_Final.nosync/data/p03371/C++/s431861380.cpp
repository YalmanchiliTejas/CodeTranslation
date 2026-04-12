#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

int main() {
  ll A, B, C, X, Y;
  scanf("%lld %lld %lld %lld %lld", &A, &B, &C, &X, &Y);

  ll price1 = A * X + B * Y;

  ll price2 = C * max(X, Y) * 2;

  ll price3 = 0;
  if (X < Y) {
    price3 += C * X * 2;
    price3 += B * (Y - X);
  } else {
    price3 += C * Y * 2;
    price3 += A * (X - Y);
  }
  cout << min(price3, min(price1, price2)) << endl;
}
