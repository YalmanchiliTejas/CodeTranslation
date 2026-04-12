#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

template<typename T>
istream& operator >> (istream& is, vector<T>& vs){
  for(T& v: vs) is >> v;
  return is;
}

int main() {
  LL N; cin >> N;
  vector<LL> A(N), S(N); cin >> A;
  S[N-1] = 0;
  for (int i = N - 2; i >= 0; --i) S[i] = (S[i + 1] + A[i + 1]) % kMod;

  LL sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += A[i] * S[i];
    sum %= kMod;
  }
  cout << sum << endl;
}
