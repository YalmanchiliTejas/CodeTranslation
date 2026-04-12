#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
typedef long long ll;
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint
{
   ll x; // typedef long long ll;
   mint(ll x = 0) : x((x % mod + mod) % mod) {}
   mint operator-() const { return mint(-x); }
   mint &operator+=(const mint a)
   {
      if ((x += a.x) >= mod)
         x -= mod;
      return *this;
   }
   mint &operator-=(const mint a)
   {
      if ((x += mod - a.x) >= mod)
         x -= mod;
      return *this;
   }
   mint &operator*=(const mint a)
   {
      (x *= a.x) %= mod;
      return *this;
   }
   mint operator+(const mint a) const { return mint(*this) += a; }
   mint operator-(const mint a) const { return mint(*this) -= a; }
   mint operator*(const mint a) const { return mint(*this) *= a; }
   mint pow(ll t) const
   {
      if (!t)
         return 1;
      mint a = pow(t >> 1);
      a *= a;
      if (t & 1)
         a *= *this;
      return a;
   }

   // for prime mod
   mint inv() const { return pow(mod - 2); }
   mint &operator/=(const mint a) { return *this *= a.inv(); }
   mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
int main()
{
   int N;
   cin >> N;
   vector<int> A(N);
   for (int i = 0; i < N; i++)
   {
      cin >> A[i];
   }
   mint ans = 0;
   mint sum = 0;
   for (int i = N - 1; i >= 0; i--)
   {
      ans += sum * A[i];
      sum += A[i];
   }
   cout << ans << endl;
   return 0;
}
