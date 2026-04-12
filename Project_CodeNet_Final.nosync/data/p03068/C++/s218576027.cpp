#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main(void) {
  ll N, K;
  string S;
  cin >> N >> S >> K;

  for (int i = 0; i < N; i++) {
    cout << (S[i] != S[K - 1] ? '*' : S[i]);
  }
  cout << endl;
}
