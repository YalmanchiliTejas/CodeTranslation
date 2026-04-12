#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 2e5 + 10;
ll a[N], sum[N], dp[N][2];
const ll INF = 1e18;

map<pair<int,int>, ll> memo;

ll get(int n, int k) {
  if (n == 0 && k == 0) return 0;
  if (n < 2 * k - 1 || n < 1) return -INF;
  if (k == 0) return 0;
  if (n == 2 * k - 1) return sum[n];
  if (memo.find(PII(n,k)) == memo.end()) {
    memo[PII(n,k)] = max(a[n] + get(n - 2, k - 1), get(n - 1, k));
  }
  return memo[PII(n,k)];
}

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = a[i];
    if (i >= 2) sum[i] += sum[i - 2];
  }
  cout << get(n, n / 2) << endl;

  return 0;
}
