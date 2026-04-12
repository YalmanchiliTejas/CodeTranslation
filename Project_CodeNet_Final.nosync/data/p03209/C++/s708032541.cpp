#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const long long mod2 = 998244353;
const long long INF = 1LL << 60;
const int inf = pow(10, 9) + 7;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, int B) {return (A + (B - 1)) / B;}
long long divCeil(int A, long long B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, long long B) {return (A + (B - 1)) / B;}

vector<long long> memolayer(100, 0);
long long layer(int L)
{
  if (memolayer.at(L) > 0) return memolayer.at(L);
  long long ret = 1;
  if (L > 0) ret = layer(L - 1) * 2 + 3;
  memolayer.at(L) = ret;
  return ret;
}

vector<long long> memopatio(100, 0);
long long patio(int L)
{
  if (memopatio.at(L) > 0) return memopatio.at(L);
  long long ret = 1;
  if (L > 0) ret = patio(L - 1) * 2 + 1;
  memopatio.at(L) = ret;
  return ret;
}

long long ans(int N, long long X)
{
  if (N < 0) return 0;
  if (X < 0) return 0;
  if (N == 0) return min(X, (long long)1);
  if (X <= 1) return 0;
  if (X <= layer(N - 1) + 1) return ans(N - 1, X - 1);
  if (X == layer(N - 1) + 2) return ans(N - 1, X - 1) + 1;
  if (X < layer(N)) return patio(N) - ans(N, layer(N) - X);
  return patio(N);
}

int main()
{
  int N;
  long long X;
  cin >> N >> X;

  cout << ans(N, X) << endl;
}