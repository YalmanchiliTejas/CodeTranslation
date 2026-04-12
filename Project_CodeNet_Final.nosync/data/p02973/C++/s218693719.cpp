#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100010;
const ll INF = 1e9 + 10;
ll dp[MAXN];

int main() {
   int N;
   cin >> N;
   ll a[N];
   for (int i = 0; i < N; i++) cin >> a[i];
   reverse(a, a + N);
   fill(dp, dp + N, INF);
   for (int i = 0; i < N; i++) {
      *upper_bound(dp, dp + N, a[i]) = a[i];
   }
   int ans = lower_bound(dp, dp + N, INF) - dp;
   cout << ans << endl;
   return 0;
}
