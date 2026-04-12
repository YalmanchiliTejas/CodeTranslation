#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

template<typename T>
constexpr T inf = static_cast<T>(pow(10, static_cast<int>(log10(numeric_limits<T>::max())))) + 7;
constexpr llong mod = 1e9+7;

int main() {
  llong N, K;
  string S;

  cin >> N >> S >> K;
  for (int i = 0; S[i]; ++i) {
    if (S[i] != S[K-1]) {
      S[i] = '*';
    }
  }

  cout << S << endl;

  return 0;
}