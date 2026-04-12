#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

using ll = long long;
typedef pair<ll, ll> P_ll;
typedef pair<int, int> P;

const ll INF_ll = 1e17;
const int INF = 1e8;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll x = 1e9 + 7;
  vector<ll> sum_A(N);
  ll sum_a = 0;
  for (int i = 0; i < N; i++) {
    ll tmp;
    cin >> tmp;
    A[i] = tmp % x;
    sum_a += A[i];
  }
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    sum_a -= A[i];
    ll tmp_x = sum_a % x;
    sum += (A[i] * tmp_x) % x;
  }

  cout << sum % x << endl;
  return 0;
}