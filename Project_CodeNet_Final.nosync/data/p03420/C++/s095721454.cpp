#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
  ll N, K, a, b, ans = 0;
  cin >> N >> K;
  if (K == 0) {
    cout << N*N << endl;
    return 0;
  }
  for (int i = 1; i <= N - K; i++) {
    b = K + i;
    ans += N/b*i + max(0LL, N%b - K + 1);
  }
  cout << ans << endl;
  return 0;
}
