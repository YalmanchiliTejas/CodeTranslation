#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
  #define debug(...) printf(__VA_ARGS__)
#else
  #define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

int main() {
  int N, K;
  cin >> N >> K;
  ll ans = 0;
  for (int b = K + 1; b <= N; b++) {
    int t = 0;
    t = (b - K) * (N / b);
    t += max((N % b) - K + 1, 0);
    debug("%d - %d\n", b, t);
    ans += t;
  }
  if (K == 0)
    ans -= N;
  cout << ans << endl;
  return 0;
}
