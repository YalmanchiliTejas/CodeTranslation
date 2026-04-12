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
  ll N;
  cin >> N;
  vector<ll> H(N, 0);
  for (int i = 0; i < N; i++) cin >> H[i];

  int count = 1;
  ll maxH = H[0];
  for (int i = 1; i < N; i++) {
    maxH = max(maxH, H[i]);
    if (maxH <= H[i])
      count++;
  }
  cout << count << endl;
}
