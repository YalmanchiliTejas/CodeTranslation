#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const long long MOD = 998244353;
const long long INF = 1LL << 60;
const int inf = pow(10, 9) + 7;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int a, int B) {return (a + (B - 1)) / B;}
long long divCeil(long long a, int B) {return (a + (B - 1)) / B;}
long long divCeil(int a, long long B) {return (a + (B - 1)) / B;}
long long divCeil(long long a, long long B) {return (a + (B - 1)) / B;}

int main()
{
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int ans = (X - Z) / (Y + Z);

  cout << ans << endl;
}