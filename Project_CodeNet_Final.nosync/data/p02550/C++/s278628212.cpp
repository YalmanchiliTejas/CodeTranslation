#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  ll N, X, M;
  cin >> N >> X >> M;


  ll k = 0;
  vector<ll> count(M, -1);
  vector<ll> sum;
  count[X] = k;
  sum.push_back(X);

  k++;
  while (true) {
    X *= X;
    X %= M;
    if (count[X] >= 0) break;
    count[X] = k;
    sum.push_back(sum[k - 1] + X);
    k++;
    if (k == N) {
      cout << sum[k - 1] << endl;
      return 0;
    }
  }

  ll ans = sum[count[X]];
  ll totalSum = sum[k - 1] + X;
  ll loopLength = k - count[X];
  ll loopSum = totalSum - sum[count[X]];
  N -= count[X] + 1;

  ll loopCount = N / loopLength;
  ans += loopCount * loopSum;
  N -= loopCount * loopLength;
  while (N > 0) {
    X *= X;
    X %= M;
    ans += X;
    N--;
  }

  cout << ans << endl;

  return 0;
}